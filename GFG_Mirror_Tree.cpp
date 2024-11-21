class Solution {
  public:
    Node* dfs(Node* node) {
        if(node == nullptr) return nullptr;
        
        Node* left = dfs(node -> left);
        Node* right = dfs(node -> right);
        Node* temp = left;
        node -> left = right;
        node -> right = temp;
        return node;
    }
    
    void mirror(Node* node) {
        dfs(node);
    }
};
