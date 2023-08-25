class Solution {
public:
    TreeNode* prune(TreeNode* root)
    {
        // Base Case:
        if(root == NULL) return NULL;

        // left and right child call:
        root -> left = prune(root -> left);
        root -> right = prune(root -> right);

        // condition of pruning:
        if(root -> left == NULL && root -> right == NULL && root -> val == 0) return NULL;
        
        return root;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        return prune(root);
    }
};