class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        stack<vector<int>> s;

        q.push(root);
        q.push(NULL);
        s.push({root -> val});

        vector<int> temp;
        while(!q.empty())
        {
            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode == NULL)
            {
                s.push(temp);
                temp.clear();

                if(!q.empty())
                {
                    q.push(NULL);
                }
            }

            else
            {
                if(frontNode -> left)
                {
                    q.push(frontNode -> left);
                    temp.push_back(frontNode -> left -> val);
                }

                if(frontNode -> right)
                {
                    q.push(frontNode -> right);
                    temp.push_back(frontNode -> right -> val);
                }
            }
        }

        // last NULL pointer giving empty vector entry in the stack, so remove it:
        s.pop();

        // creating ans vector from the stack:
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};