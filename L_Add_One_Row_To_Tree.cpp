class Solution {
public:
    void solve(TreeNode* root, int currDepth, int depth, int val) {
        if(currDepth == depth - 1) {
            TreeNode* leftt = new TreeNode(val);
            TreeNode* rightt = new TreeNode(val);
            leftt -> left = root -> left;
            rightt -> right = root -> right;
            root -> left = leftt;
            root -> right = rightt;
            return;
        }

        if(root -> left) solve(root -> left, currDepth + 1, depth, val);
        if(root -> right) solve(root -> right, currDepth + 1, depth, val);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // using dfs traversal:
        // if(depth == 1) {
        //     TreeNode* newRoot = new TreeNode(val);
        //     newRoot -> left = root;
        //     return newRoot;
        // }

        // solve(root, 1, depth, val);
        // return root;




        // using bfs traversal: Level order traversal
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot -> left = root;
            return newRoot;
        }

        int level = 1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(level == depth - 1) {
                    TreeNode* leftt = new TreeNode(val);
                    TreeNode* rightt = new TreeNode(val);
                    leftt -> left = node -> left;
                    rightt -> right = node -> right;
                    node -> left = leftt;
                    node -> right = rightt;
                }

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            level++;
        }
        return root;
    }
};