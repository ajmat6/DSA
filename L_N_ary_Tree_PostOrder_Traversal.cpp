class Solution {
public:
    void solve(Node* root, vector<int>& ans) {
        if(root == nullptr) return;
        for(auto i: root -> children) solve(i, ans);
        ans.push_back(root -> val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};