class Solution {
public:
    void solve(TreeNode* root,  int sum, int targetSum, vector<int>& temp, vector<vector<int>>& ans)
    {
        // Base Case:
        if(root == NULL) return;

        // if a leaf node is found:
        if(root -> left == NULL && root -> right == NULL)
        {
            // check for targetSum:
            sum += root -> val;
            if(sum == targetSum)
            {
                cout << "hello";
                temp.push_back(root -> val);
                ans.push_back(temp);
                temp.pop_back(); // backtrack
                return;
            }
        }

        temp.push_back(root -> val); // adding current node
        solve(root -> left, sum + root -> val, targetSum, temp, ans); // left node call
        solve(root -> right, sum + root -> val, targetSum, temp, ans); // right node call
        temp.pop_back(); // backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(root, sum, targetSum, temp, ans);
        return ans;
    }
};