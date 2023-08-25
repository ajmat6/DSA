class Solution {
public: 
    // finding inorder successor of a node:
    int inSuccessor(TreeNode* root)
    {
        while(root -> left != NULL)
        {
            root = root ->  left;
        }

        return root -> val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;

        // if current is the key node:
        if(root -> val == key)
        {
            // if root node is leaf node:
            if(root -> left == NULL && root -> right == NULL)
            {
                delete root;
                return NULL;
            }

            // if  one of the node of curr node is leaf and other is non leaf:
            else if(root -> left && root -> right == NULL)
            {
                TreeNode* temp = root -> left;
                return temp;
            }

            else if(root -> left == NULL && root -> right)
            {
                TreeNode* temp = root -> right;
                return temp;
            }

            // if curr node have both right and left node -> replace it with its inorder Successor:
            else if(root -> left && root -> right)
            {
                int inSucc = inSuccessor(root -> right);
                root -> val = inSucc;

                // call for inorder successor deletion:
                root -> right = deleteNode(root -> right, inSucc);
                return root;
            }
        }

        // if curr node is not a key node:
        else if(root -> val < key)
        {
            root -> right = deleteNode(root -> right, key);
            return root;
        }

        else if(root -> val > key)
        {
            root -> left = deleteNode(root -> left, key);
            return root;
        }

        return NULL; // unreachable
    }
};