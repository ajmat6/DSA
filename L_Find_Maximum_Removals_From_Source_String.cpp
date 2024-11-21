class Solution {
public:
    long long dfs(string& source, string& pattern, int index1, int index2, unordered_map<int, int>& mp, vector<vector<int>>& dp) {
        if(index2 == pattern.size()) return 0;
        if(index1 == source.size()) return INT_MAX;

        if(dp[index1][index2] != -1) return dp[index1][index2];

        long long ans = dfs(source, pattern, index1 + 1, index2, mp, dp);
        if(source[index1] == pattern[index2]) {
            long long take = dfs(source, pattern, index1 + 1, index2 + 1, mp, dp);
            if(mp.count(index1)) take += 1;
            ans = min(ans, take);
        }

        return dp[index1][index2] = ans;
    }

    int maxRemovals(string source, string pattern, vector<int>& t) {
        unordered_map<int, int> mp;
        for(auto i: t) mp[i]++;

        vector<vector<int>> dp (source.size() + 1, vector<int> (pattern.size() + 1, -1));
        int notDelete = dfs(source, pattern, 0, 0, mp, dp);
        return t.size() - notDelete;
    }
};