class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* temp = root;

        while(temp != NULL)
        {
            if(temp -> val > val)
            {
                if(temp -> left) temp = temp -> left;
                else 
                {
                   temp -> left = new TreeNode(val);
                   break; 
                }
            }

            else
            {
                if(temp -> right) temp = temp -> right;
                else 
                {
                   temp -> right = new TreeNode(val);
                   break; 
                }
            }
        }

        return root;
    }
};