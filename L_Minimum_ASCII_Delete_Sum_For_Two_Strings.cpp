class Solution {
public:
    int solve(string& s1, string& s2, int i, int j, vector<vector<int>>& dp)
    {
        if(i == s1.size() || j == s2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int sum = 0;
        if(s1[i] == s2[j])
        {
            sum = s1[i] + solve(s1, s2, i+1, j+1, dp);
        }

        else
        {
            int ans1 = solve(s1, s2, i+1, j, dp);
            int ans2 = solve(s1, s2, i, j+1, dp);
            
            sum = max(ans1, ans2);
        }

        dp[i][j] = sum;

        return sum;
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<char> ans;
        int sum = 0;

        for(auto i: s1) sum += i;
        for(auto i: s2) sum += i;

        vector<vector<int>> dp (s1.size(), vector<int> (s2.size(), -1));

        return sum - 2 * solve(s1, s2, 0, 0, dp);
    }
};