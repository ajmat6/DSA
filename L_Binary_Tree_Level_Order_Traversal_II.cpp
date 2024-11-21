class Solution {
public:
    int findHeight(TreeNode* root) {
        int left = 0;
        int right = 0;
        if(root -> left) left = 1 + findHeight(root -> left);
        if(root -> right) right = 1 + findHeight(root -> right);
        return max(left, right);
    }

    void dfs(TreeNode* root, int depth, vector<vector<int>>& ans) {
        ans[depth].push_back(root -> val);
        if(root -> left) dfs(root -> left, depth + 1, ans);
        if(root -> right) dfs(root -> right, depth + 1, ans);
        return;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // vector<vector<int>> ans;
        // queue<TreeNode*> q;

        // if(root == NULL) return ans;
        // q.push(root);
        // while(!q.empty()) {
        //     vector<int> temp;
        //     int n = q.size();

        //     while(n--) {
        //         TreeNode* tempo = q.front();
        //         q.pop();

        //         temp.push_back(tempo -> val);
        //         if(tempo -> left) q.push(tempo -> left);
        //         if(tempo -> right) q.push(tempo -> right);
        //     }

        //     ans.push_back(temp);
        // }

        // reverse(ans.begin(), ans.end());
        // return ans;



        // using stack:
        // queue<TreeNode*> q;
        // stack<vector<int>> st;

        // if(root == NULL) return {};
        // q.push(root);
        // while(!q.empty()) {
        //     vector<int> temp;
        //     int n = q.size();

        //     while(n--) {
        //         TreeNode* tempo = q.front();
        //         q.pop();

        //         temp.push_back(tempo -> val);
        //         if(tempo -> left) q.push(tempo -> left);
        //         if(tempo -> right) q.push(tempo -> right);
        //     }

        //     st.push(temp);
        // }

        // vector<vector<int>> ans;
        // while(!st.empty()) {
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // return ans;



        // level order traversal using dfs:
        if(root == nullptr) return {};
        int totalHeight = findHeight(root) + 1;
        vector<vector<int>> ans (totalHeight);
        dfs(root, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};