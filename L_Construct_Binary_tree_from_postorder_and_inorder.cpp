class Solution {
public:
    TreeNode* makeTree(vector<int>& inorder, vector<int>& postorder, int& currIndex, int inLow, int inHigh, unordered_map<int, int>& mp) {
        if(currIndex < 0 || inLow > inHigh) return nullptr;

        int currNodeValue = postorder[currIndex--];
        TreeNode* newNode = new TreeNode(currNodeValue);
        int index = mp[currNodeValue];

        newNode -> right = makeTree(inorder, postorder, currIndex, index + 1, inHigh, mp);
        newNode -> left = makeTree(inorder, postorder, currIndex, inLow, index - 1, mp);
        return newNode;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // mapping each value of inorder with its index:
        unordered_map<int, int> mp;
        int n = inorder.size();
        for(int i=0; i<n; i++) mp[inorder[i]] = i;

        // you can track current index in postorder by passing it as reference and only need to worry about inorder:
        int currPostIndex = n - 1;
        return makeTree(inorder, postorder, currPostIndex, 0, n - 1, mp);
    }
};