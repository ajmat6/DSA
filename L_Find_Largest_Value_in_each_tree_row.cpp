class Solution {
public:
    // DFS function to track each level values:
    void solve(TreeNode* root, unordered_map<int, int>& mp, int level)
    {
        if(root == NULL) return;

        // if level is new create it, otherwise check for bigger value:
        if(mp.find(level) == mp.end() || mp[level] < root -> val) mp[level] = root -> val;
        solve(root -> left, mp, level + 1);
        solve(root -> right, mp, level + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        // Using DFS and level track:
        // unordered_map<int, int> mp; // for tracking max level value
        // solve(root, mp, 0); // level value find

        // int size = mp.size(); // size of map
        // vector<int> ans (size); // making ans vector of map size

        // for(int i=0; i<size; i++) ans[i] = mp[i]; // forming ans vector
        // return ans;


        // Using level order traversal:
        vector<int> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            int maxi = INT_MIN;
            for(int i=0; i<size; i++)
            {
                TreeNode* front = q.front();
                q.pop();

                maxi = max(maxi, front -> val);
                if(front -> left) q.push(front -> left);
                if(front -> right) q.push(front -> right);
            }

            ans.push_back(maxi);
        }

        return ans;
    }
};