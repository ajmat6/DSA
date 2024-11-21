class Solution {
    public:
    vector<int> topView(Node *root) {
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        map<int, int> mp;
        while(!q.empty()) {
            Node* node = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if(mp.count(col) == 0) mp[col] = node -> data;
            
            if(node -> left) q.push({node -> left, col - 1});
            if(node -> right) q.push({node -> right, col + 1});
        }
        vector<int> ans;
        for(auto i: mp) ans.push_back(i.second);
        return ans;
    }
};
