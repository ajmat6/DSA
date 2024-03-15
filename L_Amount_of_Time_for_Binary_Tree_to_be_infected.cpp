class Solution {
public:
    pair<int, int> solve(TreeNode* root, int& ans, int start)
    {
        if(root == NULL) return {0, 0};

        pair<int, int> left = solve(root -> left, ans, start);
        pair<int, int> right = solve(root -> right, ans, start);

        if(root -> val == start)
        {
            ans = max(ans, max(left.second, right.second));
            return {1, 1};
        }

        else if(left.first == 1)
        {
            ans = max(ans, left.second + right.second);
            return {1, left.second + 1};
        }

        else if(right.first == 1)
        {
            ans = max(ans, left.second + right.second);
            return {1, right.second + 1};
        }

        else
        {
            ans = max(ans, max(left.second, right.second) + 1);
            return {0, max(left.second, right.second) + 1};
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;
        solve(root, ans, start);
        return ans;
    }
};