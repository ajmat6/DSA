class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // using bfs: level order traversal and queue:
        // if(root == NULL) return ans;
        // queue<TreeNode*> q;
        // vector<vector<int>> ans;

        // q.push(root);
        // int currLevel = 1;
        // vector<int> temp;
        // while(!q.empty()) {
        //     int n = q.size();

        //     while(n--) {
        //         TreeNode* tempo = q.front();
        //         q.pop();

        //         temp.push_back(tempo -> val);
        //         if(tempo -> left) q.push(tempo -> left);
        //         if(tempo -> right) q.push(tempo -> right);
        //     }

        //     if(currLevel % 2 == 1) ans.push_back(temp);
        //     else {
        //         reverse(temp.begin(), temp.end());
        //         ans.push_back(temp);
        //     }
        //     temp.clear();
        //     currLevel++;
        // }

        // return ans;




        // using stack: n time and n space:
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        stack<TreeNode*> lr;
        stack<TreeNode*> rl;
        lr.push(root);

        vector<int> temp;
        while(!lr.empty() || !rl.empty()) {
            while(!lr.empty()) {
                TreeNode* node = lr.top();
                lr.pop();

                temp.push_back(node -> val);
                if(node -> left) rl.push(node -> left);
                if(node -> right) rl.push(node -> right);
            }

            if(temp.size() > 0) {
                ans.push_back(temp);
                temp.clear();
            }

            while(!rl.empty()) {
                TreeNode* node = rl.top();
                rl.pop();

                temp.push_back(node -> val);
                if(node -> right) lr.push(node -> right);
                if(node -> left) lr.push(node -> left);
            }

            if(temp.size() > 0) {
                ans.push_back(temp);
                temp.clear();
            }
        }

        return ans;
    }
};