class Solution {
public:
    int dfs(TreeNode* root, int& ans) {
        if(root == nullptr) return 0;

        int left = max(0, dfs(root -> left, ans));
        int right = max(0, dfs(root -> right, ans));

        ans = max(ans, left + right + root -> val);
        return max(left, right) + root -> val;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
};