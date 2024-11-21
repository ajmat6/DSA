// n^2 time and height of tree space for recursive call stack
class Solution {
public:
    int findIndex(vector<int>& inorder, int val) {
        for(int i=0; i<inorder.size(); i++) {
            if(inorder[i] == val) return i;
        }
        return 0;
    }

    TreeNode* makeTree(vector<int>& inorder, vector<int>& preorder, int& currIndex, int inLow, int inHigh) {
        if(currIndex == inorder.size() || inLow > inHigh) return nullptr;

        int currNodeValue = preorder[currIndex++];
        TreeNode* newNode = new TreeNode(currNodeValue);
        int index = findIndex(inorder, currNodeValue);

        newNode -> left = makeTree(inorder, preorder, currIndex, inLow, index - 1);
        newNode -> right = makeTree(inorder, preorder, currIndex, index + 1, inHigh);
        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // you can track current index in preorder by passing it as reference and only need to worry about inorder:
        int currPreIndex = 0;
        return makeTree(inorder, preorder, currPreIndex, 0, inorder.size() - 1);
    }
};




// n time and n space:
class Solution {
public:
    TreeNode* makeTree(vector<int>& inorder, vector<int>& preorder, int& currIndex, int inLow, int inHigh, unordered_map<int, int>& mp) {
        if(currIndex == inorder.size() || inLow > inHigh) return nullptr;

        int currNodeValue = preorder[currIndex++];
        TreeNode* newNode = new TreeNode(currNodeValue);
        int index = mp[currNodeValue];

        newNode -> left = makeTree(inorder, preorder, currIndex, inLow, index - 1, mp);
        newNode -> right = makeTree(inorder, preorder, currIndex, index + 1, inHigh, mp);
        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // mapping each value of inorder with its index:
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;

        // you can track current index in preorder by passing it as reference and only need to worry about inorder:
        int currPreIndex = 0;
        return makeTree(inorder, preorder, currPreIndex, 0, inorder.size() - 1, mp);
    }
};