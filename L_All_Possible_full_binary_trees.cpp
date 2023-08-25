/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> solve(int n, unordered_map<int, vector<TreeNode*>>& dp)
    {
        if(n == 0) {};
        if(n == 1) return dp[n] = {new TreeNode(0)};
        if(n % 2 == 0) return {};

        if(dp[n].size() > 0) return dp[n];

        vector<TreeNode*> ans;

        // Each possible tree formation:
        for(int i=1; i<n; i=i+2)
        {
            vector<TreeNode*> left = solve(i, dp);
            vector<TreeNode*> right = solve(n-i-1, dp); // total - left side nodes - 1 (root node)

            for(TreeNode* l: left)
            {
                for(TreeNode* r: right)
                {
                    TreeNode* root = new TreeNode();
                    root -> left = l;
                    root -> right = r;
                    ans.push_back(root);
                }
            }
        }

        dp[n] = ans;

        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        // return solve(n);

        // Memorisation:
        unordered_map<int, vector<TreeNode*>> dp;
        return solve(n, dp);
    }
};