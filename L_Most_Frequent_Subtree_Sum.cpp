
class Solution {
public:
    int solve(TreeNode* root, unordered_map<int, int>& mp)
    {
       if(root == NULL) return 0;

       // leaf node mapping as it is also a subtree:
       if(root -> left == NULL && root -> right == NULL)
       {
           mp[root -> val]++;
           return root -> val;
       }

       int leftNodeValue = solve(root -> left, mp);
       int rightNodeValue = solve(root -> right, mp);
       
       // mapping for subtree values:
       int total = root -> val + leftNodeValue + rightNodeValue;
       mp[total]++;
       return total;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        solve(root, mp);

        // finding max freq:
        int maxFreq = INT_MIN;
        for(auto i: mp)
        {
            maxFreq = max(maxFreq, i.second);
        }

        // finding max freq sum:
        vector<int> ans;
        for(auto i: mp)
        {
            if(i.second == maxFreq) ans.push_back(i.first);
        }
        return ans;
    }
};