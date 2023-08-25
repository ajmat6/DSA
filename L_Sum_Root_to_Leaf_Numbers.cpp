class Solution {
public:
    void solve(TreeNode* root, string s, int& ans)
    {
        if(root == NULL) return;
        if(root -> left == NULL && root -> right == NULL)
        {
            string str = to_string(root -> val);
            s += str;
            ans = ans + stoi(s);
            s.pop_back(); // backtrack
            return;
        }

        string str = to_string(root -> val);
        s += str;
        solve(root -> left, s, ans);
        solve(root -> right, s, ans);
        s.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root, "", ans);
        return ans;
    }
};