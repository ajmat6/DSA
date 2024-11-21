class Solution {
public:
    void dfs(TreeNode* root, vector<int>& inorder) {
        if(root == nullptr) return;
        dfs(root -> left, inorder);
        inorder.push_back(root -> val);
        dfs(root -> right, inorder);
    }

    void DFS(TreeNode* root, int& count, int& ans, int& k) {
        if(!root) return;

        DFS(root -> left, count, ans, k);
        if(ans != -1) return;
        count += 1;
        if(count == k) {
            ans = root -> val;
            return;
        }
        DFS(root -> right, count, ans, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        // brute force: using inorder traversal: n time and n space for storing inorder traversal
        // vector<int> inorder;
        // dfs(root, inorder);
        // return inorder[k - 1];



        // optimal: n time and recursive stack space:
        int ans = -1;
        int count = 0;
        DFS(root, count, ans, k);
        return ans;
    }
};