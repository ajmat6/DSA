class Solution {
public:
    TreeNode* solve(TreeNode* root, int start, int end) {
        if(root == NULL || root -> val == start || root -> val == end) return root;

        TreeNode* left = solve(root -> left, start, end);
        TreeNode* right = solve(root -> right, start, end);

        if(!left) return right;
        if(!right) return left;
        return root;
    }

    // path find function:
    int path(TreeNode* root, int value, string& ans) {
        if(root == NULL) return 0;
        if(root -> val == value) return 1;
        
        ans.push_back('L');
        if(path(root -> left, value, ans)) return 1;
        ans.pop_back();

        ans.push_back('R');
        if(path(root -> right, value, ans) return 1;
        ans.pop_back();

        return 0;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        // find lowest common ancestor:
        TreeNode* LCA = solve(root, startValue, destValue);

        // path from LCA to start node and reverse it:
        string startPath = "";
        path(LCA, startValue, startPath);
        if(startPath.size() > 0) {
            int n = startPath.size();
            startPath = string(n, 'U');
        }

        // path from LCA to dest node and reverse it:
        string endPath = "";
        path(LCA, destValue, endPath);

        return startPath + endPath;
    }
};