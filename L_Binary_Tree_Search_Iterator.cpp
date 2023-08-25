/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> inOrder;

    void inorder(TreeNode* root)
    {
        if(root == NULL) return;

        inorder(root -> left);
        inOrder.push_back(root -> val);
        inorder(root -> right);
    }
    int i;
    BSTIterator(TreeNode* root) {
        inOrder.push_back(-1);
        inorder(root);
        i = 0;
    }
    
    int next() {
        i = i + 1;
        return inOrder[i];
    }
    
    bool hasNext() {
        if(i + 1 < inOrder.size()) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */