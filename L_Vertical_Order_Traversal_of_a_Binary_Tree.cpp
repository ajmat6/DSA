// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         queue<pair<TreeNode*, int>> q;
//         q.push({root, 0});

//         map<int, vector<int>> mp;
//         while(!q.empty()) {
//             int size = q.size();
//             unordered_map<int, multiset<int>> mp2;
//             for(int i=1; i<=size; i++) {
//                 auto front = q.front(); q.pop();
//                 int value = front.first -> val;
//                 int col = front.second;
//                 mp2[col].insert(value);

//                 if(front.first -> left) q.push({front.first -> left, col - 1});
//                 if(front.first -> right) q.push({front.first -> right, col + 1});
//             }

//             for(auto i: mp2) {
//                 for(auto j: i.second) {
//                     mp[i.first].push_back(j);
//                 }
//             }

//         }
//         vector<vector<int>> ans;
//         for(auto i: mp) ans.push_back(i.second);
//         return ans;
//     }
// };




class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q; // <node, <row, col>>
        q.push({root, {0, 0}});

        map<int, map<int, multiset<int>>> mp; // <col, <row, values>>
        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            mp[col][row].insert(node -> val);
            if(node -> left) q.push({node -> left, {row + 1, col - 1}});
            if(node -> right) q.push({node -> right, {row + 1, col + 1}});
        }

        vector<vector<int>> ans;
        for(auto i: mp) {
            vector<int> temp;
            for(auto j: i.second) {
                for(auto k: j.second) temp.push_back(k);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};