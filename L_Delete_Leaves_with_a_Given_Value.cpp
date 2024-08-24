class Solution {
public:
    TreeNode* solve(TreeNode* root, int target) {
        if(root == NULL) return NULL;
        if(root -> left == NULL && root -> right == NULL && root -> val == target) return NULL;
        root -> left = solve(root -> left, target);
        root -> right = solve(root -> right, target);
        if(root -> left == NULL && root -> right == NULL && root -> val == target) return solve(root, target);
        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root -> right == NULL && root -> left == NULL && root -> val == target) return NULL;
        else return solve(root, target);
    }
};