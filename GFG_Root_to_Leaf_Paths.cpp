class Solution {
  public:
    void dfs(Node* root, vector<vector<int>>& ans, vector<int>& temp) {
        temp.push_back(root -> data);
        if(!root -> left && !root -> right) {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        if(root -> left) dfs(root -> left, ans, temp);
        if(root -> right) dfs(root -> right, ans, temp);
        temp.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(root, ans, temp);
        return ans;
    }
};