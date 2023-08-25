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