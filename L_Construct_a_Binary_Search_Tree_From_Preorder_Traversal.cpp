class Solution {
public:
    TreeNode* makeTree(vector<int>& preorder, int& currIndex, int low, int high) {
        if(currIndex == preorder.size()) return nullptr;
        if(preorder[currIndex] < low || preorder[currIndex] > high) return nullptr;

        TreeNode* newNode = new TreeNode(preorder[currIndex++]);
        newNode -> left = makeTree(preorder, currIndex, low, newNode -> val);
        newNode -> right = makeTree(preorder, currIndex, newNode -> val, high);
        return newNode;
    }

    TreeNode* dfs(vector<int>& preorder, int low, int high) {
        if(low > high) return nullptr;

        // find index from which element will go in right side:
        int index = high + 1;
        for(int i=low+1; i<=high; i++) {
            if(preorder[i] > preorder[low]) {
                index = i;
                break;
            }
        }

        TreeNode* newNode = new TreeNode(preorder[low]);
        newNode -> left = dfs(preorder, low + 1, index - 1);
        newNode -> right = dfs(preorder, index, high);
        return newNode;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // int currIndex = 0;
        // return makeTree(preorder, currIndex, INT_MIN, INT_MAX);


        // using indexing:
        return dfs(preorder, 0, preorder.size() - 1);
    }
};