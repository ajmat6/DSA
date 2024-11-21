class Solution {
  public:
    vector<int> countOccurrences(int n, int q, vector<int> &arr, vector<vector<int>> &queries) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
    
        vector<int> ans;
        for (auto &query : queries) {
            int left = query[0];
            int right = query[1];
            int val = query[2];
    
            int leftIndex = lower_bound(mp[val].begin(), mp[val].end(), left) - mp[val].begin();
            int rightIndex = upper_bound(mp[val].begin(), mp[val].end(), right) - mp[val].begin();
            ans.push_back(rightIndex - leftIndex);
        }
    
        return ans;
    }
};