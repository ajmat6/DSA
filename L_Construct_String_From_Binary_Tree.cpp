class Solution {
public:
    void solve(TreeNode* root, string& ans)
    {
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL) 
        {
            ans += to_string(root -> val);
            return;
        }

        // ans.push_back(root -> val + '0');
        ans += to_string(root -> val);
        
        ans.push_back('(');
        solve(root -> left, ans);
        ans.push_back(')');
        if(root -> right)
        {
            ans.push_back('(');
            solve(root -> right, ans);
            ans.push_back(')');
        }
    }

    string tree2str(TreeNode* root) {
        string ans = "";
        solve(root, ans);
        return ans;
    }
};