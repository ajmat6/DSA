class Solution {
public:
    int ans = 0; int level = -1;
    void dfs(TreeNode* root, int height) {
        if(!root) return;

        if(height >= level) {
            ans = root -> val;
            level = height;
        }
        if(root -> right) dfs(root -> right, height + 1);
        if(root -> left) dfs(root -> left, height + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        // Using level order traversal (BFS):
        queue<TreeNode*> q;
        q.push(root);

        int ans = root -> val;
        while(!q.empty()) {
            auto front = q.front(); q.pop();
            ans = front -> val; 
            if(front -> right) q.push(front -> right);
            if(front -> left) q.push(front -> left);
        }

        return ans;

        // Using DFS:
        dfs(root, 0);
        return ans;
    }
};