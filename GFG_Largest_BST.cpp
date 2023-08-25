class NodeValue
{
    public:
    int size;
    int minValue;
    int maxValue;
    
    NodeValue(int size, int minValue, int maxValue)
    {
        this -> size = size;
        this -> minValue = minValue;
        this -> maxValue = maxValue;
    }
};

class Solution{
    public:
    NodeValue* solve(Node* root)
    {
        // Base Case:
        if(root == NULL)
        {
            return new NodeValue(0, INT_MAX, INT_MIN); // <size, smallest, largest>
        }
        
        // leaf Node:
        if(root -> left == NULL && root -> right == NULL)
        {
            return new NodeValue(1, root -> data, root -> data);
        }
        
        NodeValue* leftTree = solve(root -> left);
        NodeValue* rightTree = solve(root -> right);
        
        // if BST is formed:
        if(root -> data > leftTree -> maxValue && root -> data < rightTree -> minValue)
        {
            // size set:
            int newSize = 1 + leftTree -> size + rightTree -> size;
            
            // min set:
            int min;
            if(root -> left == NULL)
            {
                min = root -> data;
            }
            else min = leftTree -> minValue;
            
            // max Set:
            int max;
            if(root -> right == NULL) max = root -> data;
            else max = rightTree -> maxValue;
            
            return new NodeValue(newSize, min, max);
        }
        
        // if BST is not formed:
        else
        {
            int newSize = max(leftTree -> size, rightTree -> size);
            int min = INT_MIN;
            int max = INT_MAX;
            
            return new NodeValue(newSize, min, max);
        }
    }
    
    int largestBst(Node *root)
    {
    	NodeValue* ans = solve(root);
    	return ans -> size;
    }
};