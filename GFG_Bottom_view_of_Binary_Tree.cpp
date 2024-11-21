class Solution {
  public:
    vector <int> bottomView(Node *root) {
        queue<pair<Node*, int>> q; // node and horizontal distance (col)
        q.push({root, 0});
        
        map<int, int> mp;
        while(!q.empty()) {
            Node* node = q.front().first;
            int col = q.front().second;
            q.pop();
            
            mp[col] = node -> data;
            if(node -> left) q.push({node -> left, col - 1});
            if(node -> right) q.push({node -> right, col + 1});
        }
        
        vector<int> ans;
        for(auto i: mp) ans.push_back(i.second);
        return ans;
    }
};