class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});

        int count = 0;
        while(!q.empty())
        {
            int size = q.size();

            int index1 = q.front().second;
            int index2 = q.back().second;
            int diff = index2 - index1 + 1;

            ans = max(ans, diff);

            for(int i=0; i<size; i++)
            {
                TreeNode* frontNode = q.front().first;
                int index = q.front().second;
                q.pop();

                if(frontNode -> left) q.push({frontNode -> left, 2 * 1LL * index + 1});
                if(frontNode ->  right) q.push({frontNode -> right, 2 * 1LL * index + 2});
            }

        }

        return ans;
    }
};