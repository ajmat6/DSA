class Solution {
public:
    bool dfs(ListNode* head, TreeNode* root) {
        if(head == nullptr) return true;
        if(root == nullptr) return false;
        if(root -> val != head -> val) return false;
        
        bool left = dfs(head -> next, root -> left);
        bool right = dfs(head -> next, root -> right);
        return left || right;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL) return false;

        // check curr, left and right side of a node:
        bool curr = false;
        bool left = false;
        bool right = false;
        if(root -> val == head -> val) curr = dfs(head, root);

        left = isSubPath(head, root -> left);
        right = isSubPath(head, root -> right);
        return curr || left || right;
    }
};