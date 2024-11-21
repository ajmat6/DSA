class Solution {
public:
    TreeNode* dfs(TreeNode* root) {
        if(root == nullptr) return nullptr;

        TreeNode* temp = root;
        TreeNode* right = root -> right; // saving context of right
        temp -> right = dfs(root -> left);
        temp -> left = nullptr;
        while(temp -> right != nullptr) temp = temp -> right;
        temp -> right = dfs(right);
        return root;
    }


    void dfs2(TreeNode* root, TreeNode*& prev) {
        if(root == nullptr) return;

        dfs2(root -> right, prev);
        dfs2(root -> left, prev);

        root -> right = prev;
        root -> left = nullptr;
        prev = root;
        return;
    }

    void flatten(TreeNode* root) {
        // using dfs: n time and n space:
        // dfs(root);


        // using dfs striver approach: n time and n space:
        // TreeNode* prev = nullptr;
        // dfs2(root, prev);



        // using stack:
        if(root == nullptr) return;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            if(curr -> right) st.push(curr -> right);
            if(curr -> left) st.push(curr -> left);

            if(!st.empty()) curr -> right = st.top();
            curr -> left = nullptr;
        }



        // using constant space:
        TreeNode* currNode = root;
        while(currNode) {
            if(currNode -> left) {
                // find inorder predecessor:
                TreeNode* temp = currNode -> left;
                while(temp -> right) temp = temp -> right;

                temp -> right = currNode -> right;
                currNode -> right = currNode -> left;
                currNode -> left = nullptr;
            }
            currNode = currNode -> right;
        }
    }
};