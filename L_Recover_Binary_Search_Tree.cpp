class Solution {
public:
    TreeNode* firstNode;
    TreeNode* secondNode;

    // finding inorder traversal:
    vector<int> InorderTraversal;
    void inorder(TreeNode* root)
    {
        if(root -> left) inorder(root -> left);
        InorderTraversal.push_back(root -> val);
        if(root -> right) inorder(root -> right);
    }

    void trackNodes(TreeNode* root,  int num1, int num2)
    {
        if(root -> left) trackNodes(root -> left, num1, num2);
        if(root -> val == num1 || root -> val == num2)
        {
            if(firstNode == NULL)
            {
                firstNode = root;
            }

            else if(firstNode != NULL && secondNode == NULL)
            {
                secondNode = root;
            }
        }
        if(root -> right) trackNodes(root -> right, num1, num2);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        int inSize = InorderTraversal.size();

        // comparing and finding interchanged nos:
        int num1;
        int num2;
        for(int i=0; i<inSize-1; i++)
        {
            if(InorderTraversal[i] > InorderTraversal[i+1])
            {
                num1 = InorderTraversal[i];
                break;
            }
        }

        for(int i=inSize-1; i>0; i--)
        {
            if(InorderTraversal[i] < InorderTraversal[i-1])
            {
                num2 = InorderTraversal[i];
                break;
            }
        }

        trackNodes(root, num1, num2);

        swap(firstNode -> val, secondNode -> val);
    }
};