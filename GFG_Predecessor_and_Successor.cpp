class Solution {
    public:
    Node* findP(Node* root, int key, Node*& ans) {
        if(root == nullptr) return nullptr;
        if(root -> key < key) {
            if(ans == nullptr) ans = root;
            if(root -> key > ans -> key) ans = root;
        }
        if(root -> key >= key) findP(root -> left, key, ans);
        else findP(root -> right, key, ans);
    }
    
    Node* findS(Node* root, int key, Node*& ans) {
        if(root == nullptr) return nullptr;
        if(root -> key > key) {
            if(ans == nullptr) ans = root;
            else if(root -> key < ans -> key) ans = root;
        }
        if(root -> key > key) findS(root -> left, key, ans);
        else findS(root -> right, key, ans);
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        // Node* temp = nullptr;
        // findP(root, key, temp);
        // pre = temp;
        // temp = nullptr;
        // findS(root, key, temp);
        // suc = temp;
        
        
        
        // iterative: n time and const space:
        Node* temp = root;
        pre = nullptr;
        suc = nullptr;
        
        // find predcessor:
        while(temp) {
            if(temp -> key >= key) temp  = temp -> left;
            else {
                pre = temp;
                temp = temp -> right;
            }
        }
        
        temp = root;
        // find successor:
        while(temp) {
            if(temp -> key > key) {
                suc = temp;
                temp  = temp -> left;
            }
            else temp = temp -> right;
        }
    }
};