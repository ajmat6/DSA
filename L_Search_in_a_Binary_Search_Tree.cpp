class Solution {
public:
    TreeNode* find(TreeNode* root, int val) {
        if(root == nullptr || root -> val == val) return root;
        else if(root -> val > val) return find(root -> left, val);
        else return find(root -> right, val);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        // using recursion;
        // return find(root, val);




        // using bfs:
        TreeNode* temp = root;
        while(temp != nullptr) {
            if(temp -> val == val) return temp;
            else if(temp -> val < val) temp = temp -> right;
            else temp = temp -> left;
        }
        return nullptr;
    }
};