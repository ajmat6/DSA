class Solution {
public:
    int solve(TreeNode* root, string temp) {
        if(root == NULL) return 0;
        if(root -> left == NULL && root -> right == NULL) {
            temp += root -> val + '0';
            return stoi(temp);
        }

        temp += root -> val + '0';
        return solve(root -> left, temp) + solve(root -> right, temp);
    }

    int sumNumbers(TreeNode* root) {
        return solve(root, "");
    }
};