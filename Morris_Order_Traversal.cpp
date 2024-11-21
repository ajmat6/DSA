// inorder using morris order traversal:
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;
        while(curr != nullptr) {
            if(!curr -> left) {
                ans.push_back(curr -> val);
                curr = curr -> right;
            }

            else {
                TreeNode* temp = curr -> left;
                while(temp -> right && temp -> right != curr) temp = temp ->  right;
                if(temp -> right == nullptr) {
                    temp -> right = curr;
                    curr = curr -> left;
                }
                else {
                    temp -> right = nullptr;
                    ans.push_back(curr -> val);
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }
};



// preorder using morris order traversal:
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;
        while(curr != nullptr) {
            if(!curr -> left) {
                ans.push_back(curr -> val);
                curr = curr -> right;
            }
            else {
                TreeNode* temp = curr -> left;
                while(temp -> right && temp -> right != curr) temp = temp ->  right;
                if(temp -> right == nullptr) {
                    temp -> right = curr;
                    ans.push_back(curr -> val);
                    curr = curr -> left;
                }
                else {
                    temp -> right = nullptr;
                    curr = curr -> right;
                }
            }
        }
        return ans;
    }
};