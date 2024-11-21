#define ll long long
class Solution {
public:
    const ll mod = 1e10;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});

        ll ans = 0;
        while(!q.empty()) {
            int size = q.size();
            ll firstIndex = q.front().second;
            ll lastIndex = q.back().second;
            ans = max(ans, lastIndex - firstIndex + 1);

            for(int i=1; i<=size; i++) {
                TreeNode* node = q.front().first;
                ll index = q.front().second;
                q.pop();

                if(node -> left) q.push({node -> left, (2 * index + 1) % mod});
                if(node -> right) q.push({node -> right, (2 * index + 2) % mod});
            }
        }
        return ans;
    }
};