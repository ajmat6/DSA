class Solution {
public:
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;
        if(root == p || root == q) return root;
        if((p -> val < root -> val && q -> val > root -> val) || (p -> val > root -> val && q -> val < root -> val)) return root;
        if(p -> val < root -> val) return find(root -> left, p, q);
        return find(root -> right, p, q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return find(root, p, q); n time and h recursive space:



        // iterative:
        TreeNode* temp = root;
        while(temp) {
            if(temp == p || temp == q) return temp;
            if((p -> val < temp -> val && q -> val > temp -> val) || (p -> val > temp -> val && q -> val < temp -> val)) return temp;

            if(p -> val < temp -> val) temp = temp -> left;
            else temp = temp -> right;
        }
        return nullptr;
    }
};