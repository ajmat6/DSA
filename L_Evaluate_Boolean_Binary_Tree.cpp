class Solution {
public:
    bool solve(TreeNode* root) {
        if(!root -> left && !root -> right) return root -> val == 0 ? false : true;
        return root -> val == 2 ? solve(root -> left) || solve(root -> right) : solve(root -> left) && solve(root -> right);
    }
    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};