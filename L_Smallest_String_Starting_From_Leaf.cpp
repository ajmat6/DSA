class Solution {
public:
    void solve(TreeNode* root, string temp, string& ans) {
        if(root -> left == NULL && root -> right == NULL) {
            temp += root -> val + 'a';
            reverse(temp.begin(), temp.end());
            if(ans == "" || temp < ans) ans = temp;
            return;
        }

        temp += root -> val + 'a';
        if(root -> left) solve(root -> left, temp, ans);
        if(root -> right) solve(root -> right, temp, ans);
    }

    string smallestFromLeaf(TreeNode* root) {
        // // using dfs
        // string ans = "";
        // solve(root, "", ans);
        // return ans;




        // using bfs:
        string ans = "";
        queue<pair<TreeNode*, string>> q;
        q.push({root, ""});

        while(!q.empty()) {
            auto front = q.front(); q.pop();
            TreeNode* node = front.first;
            string s = front.second;
            s += node -> val + 'a';

            if(node -> left == NULL && node -> right == NULL) {
                reverse(s.begin(), s.end());
                if(ans == "" || s < ans) ans = s;
                continue;
            }

            if(node -> left) q.push({node -> left, s});
            if(node -> right) q.push({node -> right, s});
        }

        return ans;
    }
};