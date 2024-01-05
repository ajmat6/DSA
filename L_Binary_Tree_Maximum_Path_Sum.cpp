class Solution {
public:
    int solve(TreeNode* root, int& ans)
    {
        if(root == NULL) return 0;

        int temp = root -> val;
        int left = 0;
        int right = 0;
        if(root -> left)
        {
            left = solve(root -> left, ans);
            if(temp + left >= temp) temp += left;
        }
        if(root -> right)
        {
            right = solve(root -> right, ans);
            if(temp + right >= temp) temp += right;
        }

        ans = max(ans, temp);

        return max(root -> val, (max(root -> val + right, root -> val + left)));
    }
    int maxPathSum(TreeNode* root) {
        if(root -> left == NULL && root -> right == NULL) return root -> val;

        int ans = root -> val;
        solve(root, ans);
        return ans;
    }
};