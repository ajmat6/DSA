class Solution {
public:
    bool dfs(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2 || root1 -> val != root2 -> val) return false;

        // int left1 = -1, right1 = -1, left2 = -1, right2 = -1;
        // if(root1 -> left) left1 = root1 -> left -> val;
        // if(root1 -> right) right1 = root1 -> right -> val;
        // if(root2 -> left) left2 = root2 -> left -> val;
        // if(root2 -> right) right2 = root2 -> right -> val;

        // if(left1 == left2 && right1 == right2) 
        //     return dfs(root1 -> left, root2 -> left) && dfs(root1 -> right, root2 -> right);
        // if(left1 == right2 && right1 == left2) {
        //     TreeNode* node = root1 -> left;
        //     root1 -> left = root1 -> right;
        //     root1 -> right = node;
        //     return dfs(root1 -> left, root2 -> left) && dfs(root1 ->  right, root2 -> right);
        // }
        // return false;

        return (dfs(root1 -> left, root2 -> left) || dfs(root1 -> left, root2 -> right)) && (dfs(root1 -> right, root2 -> right) || dfs(root1 -> right, root2 -> left));
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};