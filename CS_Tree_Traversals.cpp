void dfs(TreeNode* root, vector<vector<int>>& ans) {
    if(root == nullptr) return;

    ans[1].push_back(root -> data);
    dfs(root -> left, ans);
    ans[0].push_back(root -> data);
    dfs(root -> right, ans);
    ans[2].push_back(root -> data);
    return;
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // vector<vector<int>> ans (3);
    // dfs(root, ans);
    // return ans;




    // iterative using stack:
    vector<vector<int>> ans (3);
    stack<pair<TreeNode*, int>> st; // node and curr traversal: 1 for pre, 2 for in and 3 for post
    st.push({root, 1});

    while(!st.empty()) {
        TreeNode* node = st.top().first;
        int curr = st.top().second;
        st.pop();

        // pre:
        if(curr == 1) {
            ans[1].push_back(node -> data);
            st.push({node, curr + 1});
            if(node -> left) st.push({node -> left, 1});
        }

        // inorder:
        else if(curr == 2) {
            ans[0].push_back(node -> data);
            st.push({node, curr + 1});
            if(node -> right) st.push({node -> right, 1});
        }

        else {
            ans[2].push_back(node -> data);
        }
    }
    return ans;
}