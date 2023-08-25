class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";

        queue<TreeNode*> q;
        q.push(root);
        string ans = "";

        while(!q.empty())
        {
            auto currNode = q.front();
            q.pop();

            // left node:
            if(currNode == NULL) ans.append("#,");
            else
            {
                ans.append(to_string(currNode -> val)+',');
                q.push(currNode -> left);
                q.push(currNode -> right);
            } 
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // if empty string:
        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ','); // <from where to read, in which to put, terminating character to read>

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* currNode = q.front();
            q.pop();

            getline(s, str, ',');

            // if # then it is null node:
            if(str == "#") currNode -> left = NULL;
            else
            {
                TreeNode* left = new TreeNode(stoi(str));
                currNode -> left = left;
                q.push(left);
            }

            getline(s, str, ',');
            if(str == "#") currNode -> right = NULL;
            else
            {
                TreeNode* right = new TreeNode(stoi(str));
                currNode -> right = right;
                q.push(right);
            }

        }

        return root;
    }
};