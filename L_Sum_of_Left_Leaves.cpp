class Solution {
public:
    int solve(TreeNode* root, char node) {
        if(root == nullptr) return 0;
        if(!root -> right && !root -> left && node == 'l') return root -> val;
        return solve(root -> right, 'r') + solve(root -> left, 'l');
    }

    int sumOfLeftLeaves(TreeNode* root) {
        // using dfs:
        return solve(root, 'r');


        // using level order traversal:
        queue<pair<TreeNode*, bool>> q; // bool for keeping track of left leaf:
        q.push({root, false});

        int ans = 0;
        while(!q.empty()) {
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            bool isLeft = front.second;

            if(!node -> left && !node -> right && isLeft) ans += node -> val;
            if(node -> left) q.push({node -> left, true});
            if(node -> right) q.push({node -> right, false});
        }

        return ans;
    }
};