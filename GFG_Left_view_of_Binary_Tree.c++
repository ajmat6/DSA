void dfs(Node* root, vector<int>& ans, int level) {
    if(ans.size() == level) ans.push_back(root -> data);
    if(root -> left) dfs(root -> left, ans, level + 1);
    if(root -> right) dfs(root -> right, ans, level + 1);
    return;
}

vector<int> leftView(Node *root){
    // bfs: n time and n extra space for queue:
    // if(!root) return {};
    // queue<Node*> q;
    // q.push(root);
    
    // vector<int> ans;
    // while(!q.empty()) {
    //     int size = q.size();
    //     ans.push_back(q.front() -> data);
    //     for(int i=0; i<size; i++) {
    //         Node* node = q.front();
    //         q.pop();
    //         if(node -> left) q.push(node -> left);
    //         if(node -> right) q.push(node -> right);
    //     }
    // }
    // return ans;
    
    
    
    // using dfs: n time and n space only for and vector and recursive stack space
    vector<int> ans;
    dfs(root, ans, 0);
    return ans;
}
