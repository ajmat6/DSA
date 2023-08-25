class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q; // {{node, level}, prev};
        q.push(root);
        int level = 0;

        while(!q.empty())
        {
            int size = q.size();
            int index = 0;
            int prev = 0;

            for(int i=0; i<size; i++)
            {
                cout << "level is " << level << " ";
                TreeNode* front = q.front();
                q.pop();

                // if front is first node of the level:
                if(index == 0)
                {
                    // even level conditions:
                    if(level % 2  == 0)
                    {
                        if(front -> val % 2 == 0) return false;
                        prev = front -> val;
                    } 

                    // odd level conditions:
                    else
                    {
                        if(front -> val % 2 != 0) return false;
                        prev = front -> val;
                    }

                    index++;
                }

                // other than first node of the level:
                else
                {
                    if(level % 2 == 0)
                    {
                        if(front -> val % 2 == 0 || front -> val <= prev) return false;
                        prev = front -> val;
                    }

                    else
                    {
                        if(front -> val % 2 != 0 || front -> val >= prev) return false;
                        prev = front -> val;
                    }
                }

                // left and right child push into queue:
                if(front -> left) q.push(front -> left);
                if(front -> right ) q.push(front -> right);
            
            }

            level++;
        }

        return true;
    }
};