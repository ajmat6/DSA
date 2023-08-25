class Solution {
public:
    void solve(TreeNode* root, int val, int depth, int level)
    {
        if(level + 1 == depth)
        {
            if(root -> left)
            {
                TreeNode* Node = new TreeNode(val);
                Node -> left = root -> left;
                root -> left = Node;
            }

            else
            {
                TreeNode* Node = new TreeNode(val);
                root -> left = Node;
            }

            if(root -> right)
            {
                TreeNode* Node = new TreeNode(val);
                Node -> right = root -> right;
                root -> right = Node;
            }

            else
            {
                TreeNode* Node = new TreeNode(val);
                root -> right = Node;
            }

            return;
        }

        // left and right subtree call:
        if(root -> left) solve(root -> left, val, depth, level+1);
        if(root -> right) solve(root -> right, val, depth, level+1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // if depth is 1:
        if(depth == 1)
        {
            TreeNode* newRoot = new TreeNode(val);
            newRoot -> left = root;
            return newRoot;
        }

        solve(root, val, depth, 1);
        return root;
    }
};