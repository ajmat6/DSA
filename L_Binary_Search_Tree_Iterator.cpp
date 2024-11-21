// class BSTIterator {
// public:
//     vector<int> inorder;
//     int index;
//     void dfs(TreeNode* root, vector<int>& inorder) {
//         if(root == nullptr) return;
//         dfs(root -> left, inorder);
//         inorder.push_back(root -> val);
//         dfs(root -> right, inorder);
//     }

//     BSTIterator(TreeNode* root) {
//         dfs(root, inorder);
//         index = 0;
//     }
    
//     int next() {
//         int ans = inorder[index];
//         index++;
//         return ans;
//     }
    
//     bool hasNext() {
//         if(index < inorder.size()) return true;
//         return false;
//     }
// };




// const time and h space using stack:
class BSTIterator {
public:
    stack<TreeNode*> st;
    void pushLeft(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root -> left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushLeft(node -> right);
        return node -> val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};