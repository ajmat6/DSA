class Solution {
public:
    vector<TreeNode*> Unique(int start, int end)
    {
        // if one node:
        if(start == end)
        {
            TreeNode* node = new TreeNode(start);
            return {node};
        }

        if(start > end) return {NULL};

        vector<TreeNode*> ans;
        for(int i=start; i<=end; i++)
        {
            vector<TreeNode*> left = Unique(start, i-1);
            vector<TreeNode*> right = Unique(i+1, end);

            for(auto l: left)
            {
                for(auto r: right)
                {
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return Unique(1, n);
    }
};