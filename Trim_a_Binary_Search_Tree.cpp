class Solution {
public:
    TreeNode* solve(TreeNode* root, int low, int high)
    {
        if(root == NULL) return NULL;

        // if curr node value is less than low then all its left node are also smaller than low and similar concept for higher val:
        if(root -> val < low) return solve(root -> right, low, high);
        if(root -> val > high) return solve(root -> left, low, high);

        // if curr node is ok then calling for its children:
        root -> left = solve(root -> left, low, high);
        root -> right = solve(root -> right, low, high);

        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);
    }
};