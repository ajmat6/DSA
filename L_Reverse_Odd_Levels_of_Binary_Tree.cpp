class Solution {
public:
    void dfs(TreeNode* root, TreeNode* exNode, int level) {
        if(!root) return;
        if(level % 2) swap(root -> val, exNode -> val);
        dfs(root -> left, exNode -> right, level + 1);
        dfs(root -> right, exNode -> left, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root -> left, root -> right, 1);
        return root;
    }
};