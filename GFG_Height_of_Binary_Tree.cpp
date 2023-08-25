class Solution{
    public:
    int height(struct Node* node){
         if(node == NULL) return 0;
         
         int left = height(node -> left);
         int right = height(node -> right);
         
         int maxi = max(left, right) + 1;
         
         return maxi;
    }
};