class Solution{
    public:
    int check(Node* root) {
        if(root == nullptr) return 1;
        if(root -> left == nullptr && root -> right == nullptr) return 1;
        
        int sum = 0;
        if(root -> left) sum += root -> left -> data;
        if(root -> right) sum += root -> right -> data;
        if(root -> data != sum) return 0;
        
        int left = check(root -> left);
        int right = check(root -> right);
        return left && right;
    }
    
    int isSumProperty(Node *root) {
        return check(root);
    }
};
