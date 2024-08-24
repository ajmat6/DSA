class Solution {
public:
    vector<int> solve(TreeNode* root, int dis, int& ans) {
        if(root == nullptr) return {};
        if(!root -> left && !root -> right) return {1};

        vector<int> left = solve(root -> left, dis, ans);
        vector<int> right = solve(root -> right, dis, ans);

        vector<int> temp;
        for(auto i: left) {
            for(auto j: right) {
                if(i + j <= dis) ans += 1;
            }
            if(i < dis) temp.push_back(i + 1);
        }

        for(auto j: right) temp.push_back(j + 1);
        return temp;
    }

    void countLeaf(TreeNode* root, map<TreeNode*, TreeNode*>& mp, vector<TreeNode*>& leafs) {
        if(!root) return;
        if(!root -> left && !root -> right) {
            leafs.push_back(root);
            return;
        }

        if(root -> left) mp[root -> left] = root;
        if(root -> right) mp[root -> right] = root;

        countLeaf(root -> left, mp, leafs);
        countLeaf(root -> right, mp, leafs);
        return;
    }

    void dfs(TreeNode* root, TreeNode* prt, map<TreeNode*, TreeNode*>& mp, int& dis, int& ans, int total) {
        if(root -> left == nullptr && root -> right == nullptr && prt != NULL) {
            if(total <= dis) ans++;
            return;
        }
        if(total > dis) return;

        if(mp.find(root) != mp.end()) dfs(mp[root], root, mp, dis, ans, total + 1);
        if(root -> left && root -> left != prt) dfs(root -> left, root, mp, dis, ans, total + 1); 
        if(root -> right && root -> right != prt) dfs(root -> right, root, mp, dis, ans, total + 1); 
        return;
    }

    int countPairs(TreeNode* root, int distance) {
        // int ans = 0;
        // solve(root, distance, ans);
        // return ans;

        // using hashmap:
        map<TreeNode*, TreeNode*> mp;
        vector<TreeNode*> leafs;
        countLeaf(root, mp, leafs);

        int ans = 0;
        for(int i=0; i<leafs.size(); i++) {
            dfs(leafs[i], nullptr, mp, distance, ans, 0);
        }
        return ans / 2;
    }
};