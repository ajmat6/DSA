class Solution {
public:
void dfs(TreeNode* root, vector<string>& ans, string temp) {
        if(!root) return;
        if(!root -> left && !root -> right) {
            temp += to_string(root -> val);
            ans.push_back(temp);
            return;
        }
        
        temp += to_string(root -> val) + "->";
        dfs(root -> left, ans, temp);
        dfs(root -> right, ans, temp);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";
        dfs(root, ans, temp);
        return ans;
    }
};