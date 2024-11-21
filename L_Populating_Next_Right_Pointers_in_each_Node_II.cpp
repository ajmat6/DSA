class Solution {
public:
    Node* findNextNode(Node* root) {
        if(root == nullptr) return nullptr;
        if(root -> left) return root -> left;
        if(root -> right) return root -> right;
        return findNextNode(root -> next);
    }

    void dfs(Node* root) {
        if(root == nullptr) return;
        if(root -> left == nullptr && root -> right == nullptr) return;

        Node* nextNode = findNextNode(root -> next);
        if(root -> left) {
            if(root -> right) root -> left -> next = root -> right;
            else root -> left -> next = nextNode;
        }

        if(root -> right) root -> right -> next = nextNode;

        // do right traversal first so that you can find nextNode available:
        dfs(root -> right);
        dfs(root -> left);
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


        // using dfs: n time and const space except recursive stack space which is height of tree:
        dfs(root);
        return root;
    }
};