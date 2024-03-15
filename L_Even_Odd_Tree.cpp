
class Solution {
public:
    // TC is O(n) becoz each node is traversed once and space complexity is O(n) for queue
    bool isEvenOddTree(TreeNode* root) {
        // using level order traversal:
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);

        while(!q.empty()) {
            int sizeOfQueue = q.size();
            int prevNodeValue = -1;
            for(int i=0; i<sizeOfQueue; i++) {
                TreeNode* node = q.front(); q.pop();
                if((level % 2 == 0) && (node -> val % 2 != 1 || node -> val <= prevNodeValue)) return false;
                else if((level % 2 == 1) && (node -> val % 2 != 0 || (prevNodeValue != -1 && node -> val >= prevNodeValue))) return false;

                // common part for both even and odd level:
                prevNodeValue = node -> val;
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
            level++;
        }

        return true;
    }
};