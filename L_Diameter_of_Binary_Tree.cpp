class Solution {
public:
    int solve(TreeNode* root, int& ans) {
        int left = 0; int right = 0;
        if(root -> left) left = 1 + solve(root -> left, ans);
        if(root -> right) right = 1 + solve(root -> right, ans);
        ans = max(ans, left + right);
        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};