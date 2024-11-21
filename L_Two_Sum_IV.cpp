class Solution {
public:
    vector<int> ans;
    void inorder(TreeNode* root)
    {
        if(root == NULL) return;

        inorder(root -> left);
        ans.push_back(root -> val);
        inorder(root -> right);
    }

    bool findTarget(TreeNode* root, int k) {
        // finding inorder
        inorder(root);

        // 2 sum problem approach:
        for(int i=0; i<ans.size(); i++)
        {
            int first = ans[i];
            for(int j=i+1; j<ans.size(); j++)
            {
                int second = ans[j];
                cout << second;

                if(first + second == k) return true;
            }
        }

        return false;
    }
};




// using iterator and dfs:
class BSTIterator {
    public:
    stack<TreeNode*> st;
    bool isReverse;
    BSTIterator(TreeNode* root, bool isRev) {
        isReverse = isRev;
        pushAll(root, isRev);
    }

    void pushAll(TreeNode* root, bool isRev) {
        while(root) {
            st.push(root);
            if(isRev) root = root -> right;
            else root = root -> left;
        }
    }

    bool isNext() {
        return !st.empty();
    }

    int next(bool isRev) {
        TreeNode* node = st.top(); st.pop();
        if(!isRev) pushAll(node -> right, false);
        else pushAll(node -> left, true);
        return node -> val;
    }
};



class Solution {
public:
    bool solve(TreeNode* first, TreeNode* second, int k) {
        if(!first || !second) return false;

        int val1 = first -> val;
        int val2 = second -> val;
        if(val1 == val2) {
            return solve(first, second -> right, k) || solve(first, second -> left, k);
        }

        if(val1 + val2 == k) return true;
        if(val1 + val2 > k) {
            bool secondLeft = solve(first, second -> left, k);
            if(secondLeft) return true;
            else return solve(first -> left, second, k);
        }
        else {
            bool secondRight = solve(first, second -> right, k);
            if(secondRight) return true;
            else return solve(first -> right, second, k);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        // using dfs: can go upto n^2 in worst case and n reucrsive stack space:
        // if(k - root -> val < root -> val) return solve(root, root -> left, k);
        // return solve(root, root -> right, k); // equal case can be in anyone





        // optimal using bst iterator: n time and h space:
        BSTIterator start(root, false);
        BSTIterator end(root, true);

        int val1 = start.next(false);
        int val2 = end.next(true);
        while(val1 < val2) {
            if(val1 + val2 == k) return true;
            else if(val1 + val2 < k && start.isNext()) val1 = start.next(false);
            else if(end.isNext()) val2 = end.next(true);
            else break;
        }
        return false;
    }
};