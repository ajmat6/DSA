class Solution {
public:
    void solve(Node* root)
    {
        if(root == NULL) return;

        if(root -> left && root -> right)
        {
            // pointing left node to its next pointer:
            root -> left -> next = root -> right;

            // pointing right node to its next pointer:
            if(root -> next != NULL)
            {
                root -> right -> next = root -> next -> left;
            }
        }

        solve(root -> left);
        solve(root -> right);
    }

    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};