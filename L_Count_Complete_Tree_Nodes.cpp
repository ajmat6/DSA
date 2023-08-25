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
    int leftHeight(TreeNode* root)
    {
        int count = 0;
        while(root)
        {
            count++;
            root = root -> left;
        }

        return count;
    }

    int rightHeight(TreeNode* root)
    {
        int count = 0;
        while(root)
        {
            count++;
            root = root -> right;
        }

        return count;
    }

    int solve(TreeNode* root)
    {
        if(root == NULL) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh) return pow(2, lh) - 1;

        int ans = 1 + solve(root -> left) + solve(root -> right);
        return ans;
    }

    int countNodes(TreeNode* root) {
        return solve(root);
    }
};