class Solution {
public:
    // O(n) space soution function:
    pair<int, int> mostFreq = {-1, 0};
    void solve(TreeNode* root, vector<int>& ans, unordered_map<int, int>& mp)
    {
        if(root == NULL) return;

        solve(root -> left, ans, mp);
        mp[root -> val]++;
        if(mostFreq.first == -1 || mostFreq.second < mp[root -> val]) mostFreq = {root -> val, mp[root -> val]};
        solve(root -> right, ans, mp);
    }


    // Optimised O(1) space solution function (except recursion stack space as mentioned in question)
    int currValue = 0;
    int currCount = 0;
    int maxCount = 0;

    void solve2(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL) return;

        solve2(root -> left, ans);
        
        // as inordere traversal gives us sorted elements:
        currCount = root -> val == currValue ? currCount + 1 : 1;
        if(currCount == maxCount) ans.push_back(root -> val);
        if(currCount > maxCount)
        {
            maxCount = currCount;
            ans = {root -> val};
        }
        currValue = root -> val;

        solve2(root -> right, ans);
    }


    vector<int> findMode(TreeNode* root) {
        // O(n) space solution:
        // vector<int> ans;
        // unordered_map<int, int> mp;
        // solve(root, ans, mp);

        // for(auto i: mp) 
        // {
        //     if(i.second == mostFreq.second) ans.push_back(i.first);
        // }

        // return ans;


        // O(1) space solution:
        vector<int> ans;
        solve2(root, ans);
        return ans;
    }
};