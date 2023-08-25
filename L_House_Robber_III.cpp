class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int solve(TreeNode* root)
    {
        if(root == NULL) return 0;

        // check for dp:
        if(dp.count(root) != 0) return dp[root];

        int include = 0;
        int exclude = 0;

        if(root -> left != NULL)
        {
            include += solve(root -> left -> left) + solve(root -> left -> right);
        }

        if(root -> right != NULL)
        {
            include += solve(root -> right -> left) + solve(root -> right -> right);
        }

        include += root -> val;

        // exlude curr node:
        exclude += solve(root -> left) + solve(root -> right);

        int ans = max(include, exclude);
        dp[root] = ans;
        return ans;
    }

    int rob(TreeNode* root) {
        return solve(root);
    }
};