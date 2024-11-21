class Solution {
public:
    bool check(TreeNode* p, TreeNode* q) {
        if((p && !q) || (!p && q)) return false;
        if(!p && !q) return true;
        if(p -> val == q -> val && check(p -> left, q -> left) && check(p -> right, q -> right)) return true;
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);
    }
};