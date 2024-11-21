class Solution {
public:
    void dfs(Node* root) {
        if(root -> left == nullptr && root -> right == nullptr) return;

        root -> left -> next = root -> right;
        if(root -> next != nullptr) root -> right -> next = root -> next -> left;

        dfs(root -> left);
        dfs(root -> right);
    }

    Node* connect(Node* root) {
        // using level order traversal: n time and n space for queue:
        // if(!root) return root;
        // queue<Node*> q;
        // q.push(root);

        // while(!q.empty()) {
        //     int size = q.size();
        //     for(int i=1; i<=size; i++) {
        //         Node* node = q.front();
        //         q.pop();
        //         if(i == size) node -> next = nullptr;
        //         else node -> next = q.front();

        //         if(node -> left) q.push(node -> left);
        //         if(node -> right) q.push(node -> right);
        //     }
        // }
        // return root;


        // using dfs:
        if(root == nullptr) return nullptr;
        root -> next = nullptr;
        dfs(root);
        return root;
    }
};