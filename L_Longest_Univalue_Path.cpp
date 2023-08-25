class Solution {
public:
    int solve(TreeNode* root, int& ans)
    {
        // Base Case:
        if(root == NULL) return 0;

        // calling for left and right trees:
        int left = solve(root -> left, ans);
        int right = solve(root -> right, ans);

        // check left node of the curr node:
        if(root -> left && root -> val == root -> left -> val)
        {
            left += 1;
        }
        else left = 0;
        
        // check for right node:
        if(root -> right && root -> val == root -> right -> val)
        {
            right += 1;
        }
        else right = 0;

        ans = max(ans, left + right);
        return max(left, right);
    }

    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};