// TC = O(n) and SC = O(n) where n are no of nodes
class Solution {
public:
    pair<int, TreeNode*> solve(TreeNode* root, int depth, TreeNode* parent)
    {
        // Base Case:
        if(root == NULL) return {depth - 1, parent};

        // left and right nodes call if exist:
        pair<int, TreeNode*> leftNode = {depth, root};
        pair<int, TreeNode*> rightNode = {depth, root};

        if(root -> left) leftNode = solve(root -> left, depth+1, root);
        if(root -> right) rightNode = solve(root -> right, depth+1, root);

        // if leftNode depth is greater:
        if(leftNode.first > rightNode.first) return leftNode;

        // if both have same then node will be root node to return:
        else if(leftNode.first == rightNode.first) return {leftNode.first, root};

        // else it will be rightNode:
        else return rightNode;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<int, TreeNode*> ans = solve(root, 0, root);
        return ans.second;
    }
};