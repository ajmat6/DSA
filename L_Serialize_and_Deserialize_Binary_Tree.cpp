// your first approach: using parentheses: n time and n space for both but leads to unnecessary () for serialization and requires stack for finiding
class Codec {
public:
    void dfs(TreeNode* root, string& ans) {
        if(root == nullptr) return;

        string temp = to_string(root -> val);
        ans += temp;

        ans += '(';
        dfs(root -> left, ans);
        ans += ')';
        ans += '(';
        dfs(root -> right, ans);
        ans += ')';
        return;
    }

    string serialize(TreeNode* root) {
        string ans = "";
        dfs(root, ans);
        return ans;
    }

    TreeNode* create(string& data, int low, int high) {
        if(low > high) return nullptr;

        // find data value and node creation:
        int nodeValue = 0;
        bool isNeg = false;
        if(data[low] == '-') {
            isNeg = true;
            low++;
        }

        while(data[low] != '(') {
            nodeValue = nodeValue * 10 + (data[low] - '0');
            low++;
        }

        if(isNeg) nodeValue *= -1;
        TreeNode* node = new TreeNode(nodeValue);


        // find left half end point:
        int index = low;
        int ansIndex = low + 1;
        stack<char> st;
        st.push(data[index++]);
        while(!st.empty()) {
            if(data[index] == '(') st.push('(');
            else if(data[index] == ')') {
                ansIndex = index;
                st.pop();
            }
            index++;
        }

        // left and right call:
        node -> left = create(data, low + 1, ansIndex - 1);
        node -> right = create(data, ansIndex + 2, high - 1);
        return node;
    }

    TreeNode* deserialize(string data) {
        return create(data, 0, data.size() - 1);
    }
};





// using level order traversal: more efficient: n time and space
class Codec {
public:
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        queue<TreeNode*> q;
        q.push(root);
        string ans = "";
        ans += to_string(root -> val);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node -> left) {
                q.push(node -> left);
                ans += "," + to_string(node -> left -> val);
            }
            else ans += ",#";
            if(node -> right) {
                q.push(node -> right);
                ans += "," + to_string(node -> right -> val);
            }
            else ans += ",#";
        }

        return ans;
    }

    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;

        string temp;
        stringstream ss(data);
        getline(ss, temp, ',');

        TreeNode* root = new TreeNode(stoi(temp));
        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty()) {
            TreeNode* node = Q.front();
            Q.pop();

            getline(ss, temp, ',');
            if(temp != "#") node -> left = new TreeNode(stoi(temp));
            else node -> left = nullptr;
            if(node -> left) Q.push(node -> left);

            getline(ss, temp, ',');
            if(temp != "#") node -> right = new TreeNode(stoi(temp));
            else node -> right = nullptr;
            if(node -> right) Q.push(node -> right);
        }

        return root;
    }
};