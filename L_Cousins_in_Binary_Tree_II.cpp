class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, root -> val});
        
        int prevSum = root -> val;
        while(!q.empty()) {
            int size = q.size();
            int currSum = 0;
            for(int i=0; i<size; i++) {
                auto front = q.front(); q.pop();

                TreeNode* node = front.first;
                int prtSum = front.second;
                node -> val = prevSum - prtSum;

                int parentSum = 0;
                if(node -> left) parentSum += node -> left -> val;
                if(node -> right) parentSum += node -> right -> val;
                if(node -> left) q.push({node -> left, parentSum});
                if(node -> right) q.push({node -> right, parentSum});
                currSum += parentSum;
            }
            prevSum = currSum;
        }
        return root;
    }
};




class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        int prevSum = root -> val;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            int currSum = 0;
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front(); q.pop();

                int parentSum = 0;
                if(node -> left) parentSum += node -> left -> val;
                if(node -> right) parentSum += node -> right -> val;
                if(node -> left) {
                    node -> left -> val = parentSum;
                    q.push(node -> left);
                }
                if(node -> right) {
                    node -> right -> val = parentSum;
                    q.push(node -> right);
                }
                currSum += parentSum;
                node -> val = prevSum - node -> val;
            }
            prevSum = currSum;
        }
        return root;
    }
};