class Solution {
public:
    vector<TreeNode*> ans;
    TreeNode* solve(TreeNode* root, set<int>& st) {
        if(root == NULL) return NULL;

        root -> left = solve(root -> left, st);
        root -> right = solve(root -> right, st);

        if(st.find(root -> val) != st.end()) {
            if(root -> left) ans.push_back(root -> left);
            if(root -> right) ans.push_back(root -> right);
            root -> left = nullptr;
            root -> right = nullptr;
            root = NULL;
            delete root;
            return nullptr;
        }

        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st;
        for(auto i: to_delete) st.insert(i);
        TreeNode* res = solve(root, st);
        if(res) ans.push_back(res);
        return ans;
    }
};