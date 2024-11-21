class Solution {
public:
    void dfsLeft(Node* root, vector<int>& ans) {
        if(!root -> left && !root -> right) return;
        ans.push_back(root -> data);
        if(root -> left) return dfsLeft(root -> left, ans);
        else return dfsLeft(root -> right, ans);
    }
    
    void dfsLeaf(Node* root, vector<int>& ans) {
        if(root -> left == nullptr && root -> right == nullptr) ans.push_back(root -> data);
        if(root -> left) dfsLeaf(root -> left, ans);
        if(root -> right) dfsLeaf(root -> right, ans);
        return;
    }
    
    void dfsRight(Node* root, vector<int>& temp) {
        if(!root -> left && !root -> right) return;
        temp.push_back(root -> data);
        if(root -> right) return dfsRight(root -> right, temp);
        else return dfsRight(root -> left, temp);
    }
    
    vector <int> boundary(Node *root) {
        vector<int> ans;
        if(root -> left) dfsLeft(root, ans);
        else ans.push_back(root -> data);
        if(root -> left || root -> right) dfsLeaf(root, ans);
        vector<int> temp;
        if(root -> right) dfsRight(root -> right, temp);
        reverse(temp.begin(), temp.end());
        for(auto i: temp) ans.push_back(i);
        return ans;
    }
};