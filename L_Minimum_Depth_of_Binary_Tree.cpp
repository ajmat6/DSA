class Solution {
public:
    int countDepth(TreeNode* root)
    {
        // if one child is null:
        if(root == NULL) return INT_MAX;

        // base case for leaf node:
        if(root -> left ==  NULL && root -> right == NULL) return 1;

        // Left Subtree:
        int left = countDepth(root -> left);

        // Right Subtree:
        int right = countDepth(root -> right);

        return min(left, right) + 1;
    }

    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return countDepth(root);
    }
};