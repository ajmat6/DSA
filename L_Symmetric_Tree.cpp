class Solution {
public:
    bool check(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;

        if(root1 -> val == root2 -> val && check(root1 -> left, root2 -> right) && check(root1 -> right, root2 -> left)) return true;
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root -> left, root -> right);
    }
};