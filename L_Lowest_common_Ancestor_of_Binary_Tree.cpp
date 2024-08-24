class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root == p) return p;
        if(root == q) return q;

        TreeNode* left = solve(root -> left, p, q);
        TreeNode* right = solve(root -> right, p, q);

        if(left && right) return root;
        if(left && !right) return left;
        if(!left && right) return right;
        return nullptr;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};