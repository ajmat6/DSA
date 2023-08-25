class Solution {
public:
    // Recursion: Gives TLE:
    int solve(string& s, string& t , int i, int j)
    {
        // Base Case of string found:
        if(j == t.size()) return 1;

        if(i == s.size()) return 0;

        int sum = 0;

        // if ith and jth character are not equal:
        if(s[i] != t[j])
        {
            return solve(s, t, i+1, j);
            
        }

        // including the current character:
        sum += solve(s, t, i+1, j+1);

        /// excluding the current character:
        sum += solve(s, t, i+1, j);

        return sum;
    }

    // Memorisation:
    int solve2(string& s, string& t , int i, int j, vector<vector<int>>& dp)
    {
        // Base Case of string found:
        if(j == t.size()) return 1;

        if(i == s.size()) return 0;

        // Cheacking for dp:
        if(dp[i][j] != -1) return dp[i][j];

        int sum = 0;

        // if ith and jth character are not equal:
        if(s[i] != t[j])
        {
            return solve2(s, t, i+1, j, dp);
            
        }

        // including the current character:
        sum += solve2(s, t, i+1, j+1, dp);

        /// excluding the current character:
        sum += solve2(s, t, i+1, j, dp);

        // storing ans in dp:
        dp[i][j] = sum;

        return sum;
    }

    // Tabulation:
    int solve3(string& s, string& t)
    {
        // 2d dp:
        vector<vector<int>> dp (s.size()+1, vector<int> (t.size()+1, 0));

        for(int i=0; i<=s.size(); i++)
        {
            dp[i][t.size()] = 1;
        }

        // Handling recursive cases:
        for(int i=s.size()-1; i>=0; i--)
        {
            for(int j=t.size()-1; j>=0; j--)
            {
                long long sum = 0;

                // if ith and jth character are not equal:
                if(s[i] != t[j])
                {
                    dp[i][j] = dp[i+1][j];
                    continue;
                }

                // including the current character:
                sum += dp[i+1][j+1];

                /// excluding the current character:
                sum += dp[i+1][j];

                // storing ans in dp:
                dp[i][j] = sum;
            }
        }

        return dp[0][0];
    }

    // Space Optimisation:
    int solve4(string& s, string& t)
    {
        // 1d vectors:
        vector<int> curr (t.size()+1, 0);
        vector<int> next (t.size()+1, 0);

        curr[t.size()] = 1;
        next[t.size()] = 1;

        // Handling recursive cases:
        for(int i=s.size()-1; i>=0; i--)
        {
            for(int j=t.size()-1; j>=0; j--)
            {
                long long sum = 0;

                // if ith and jth character are not equal:
                if(s[i] != t[j])
                {
                    curr[j] = next[j];
                    continue;
                }

                // including the current character:
                sum += next[j+1];

                /// excluding the current character:
                sum += next[j];

                // storing ans in dp:
                curr[j] = sum;
            }

            next = curr;
        }

        return curr[0];
    }

    int numDistinct(string s, string t) {
        // return solve(s, t, 0, 0);

        // Memorisation:
        // vector<vector<int>> dp (s.size()+1, vector<int> (t.size()+1, -1));
        // return solve2(s, t, 0, 0, dp);

        // Tabulation:
        // return solve3(s, t);

        // Space Optimisation:
        return solve4(s, t);
    }
};