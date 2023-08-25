class Solution {
public:
    // function to find parent pf the nodes:
    void FindParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            // check if left node exist:
            if(front -> left)
            {
                q.push(front -> left);
                parent[front -> left] = front;
            }

            // check if right node exist:
            if(front -> right)
            {
                q.push(front -> right);
                parent[front -> right] = front;
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        FindParents(root, parent);

        // queue to track nodes away from the target node:
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> isVisited;
        q.push(target);
        isVisited[target] = true;
        int kDistance = 0;

        while(!q.empty())
        {
            // if we are at k distance away from the target node:
            if(kDistance == k) break;

            // increasing distance:
            kDistance++;

            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* front = q.front();
                q.pop();

                // left node:
                if(front -> left && !isVisited[front -> left])
                {
                    q.push(front -> left);
                    isVisited[front -> left] = true;
                }

                // right node:
                if(front -> right && !isVisited[front -> right])
                {
                    q.push(front -> right);
                    isVisited[front -> right] = true;
                }

                // left node:
                if(parent[front] && !isVisited[parent[front]])
                {
                    q.push(parent[front]);
                    isVisited[parent[front]] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* front = q.front();
            int value = front -> val;
            ans.push_back(value);
            q.pop();
        }

        return ans;
    }
};