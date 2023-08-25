class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        
        queue<Node*> q;
        vector<Node*> temp;
        q.push(root);
        q.push(NULL);

        // Level Order Traversal:
        while(!q.empty())
        {
            Node* frontNode = q.front();
            q.pop();

            if(frontNode == NULL)
            {
                int size = temp.size();
                for(int i=0; i<size-1; i++)
                {
                    temp[i] -> next = temp[i+1];
                }

                temp.clear();

                // for next level:
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }

            // check if left and right node exist. If exist insert them into the queue:
            else
            {
                if(frontNode -> left)
                {
                    q.push(frontNode -> left);
                    temp.push_back(frontNode -> left);
                }

                if(frontNode -> right)
                {
                    q.push(frontNode -> right);
                    temp.push_back(frontNode -> right);
                }
            }
        }

        return root;
    }
};