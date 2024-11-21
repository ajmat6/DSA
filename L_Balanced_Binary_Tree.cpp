class Solution {
public:
    int dfs(TreeNode* root, bool& ans) {
        if(root == nullptr) return 0;
        int left = dfs(root -> left, ans);
        int right = dfs(root -> right, ans);
        if(abs(right - left) > 1) ans = false;
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool ans = true;
        dfs(root, ans);
        return ans;
    }
};



class Solution {
public:
    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = dfs(root -> left);
        int right = dfs(root -> right);
        if(left == -1 || right == -1) return -1;
        if(abs(right - left) > 1) return -1;
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) == -1 ? false : true;
    }
};