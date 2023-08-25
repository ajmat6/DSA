class Solution {
public:
    // Recursion:
    int solve(string& s, int low, int high)
    {
        // Base Case: when single character:
        if(low == high) return 1;

        int ans = INT_MAX;
        // lop over all possible combination of substrings:
        for(int i=low; i<high; i++)
        {
            int left = solve(s, low, i);
            int right = solve(s, i+1, high);

            int total = left + right;
            ans = min(ans, total);
        }

        // if first and last character is same, we can overwrite middle characters so:
        if(s[low] == s[high])
        {
            ans = ans - 1;
        }

        return ans;
    }

    // Memorisation:
    int solve2(string& s, int low, int high, vector<vector<int>>& dp)
    {
        // Base Case: when single character:
        if(low == high) return 1;

        if(dp[low][high] != -1) return dp[low][high];

        int ans = INT_MAX;
        // lop over all possible combination of substrings:
        for(int i=low; i<high; i++)
        {
            int left = solve2(s, low, i, dp);
            int right = solve2(s, i+1, high, dp);

            int total = left + right;
            ans = min(ans, total);
        }

        // if first and last character is same, we can overwrite middle characters so:
        if(s[low] == s[high])
        {
            ans = ans - 1;
        }

        return dp[low][high] = ans;
    }

    // Tabulation:
    int solve3(string& s)
    {
        int n = s.size();
        vector<vector<int>> dp (n+1, vector<int> (n+1, 0));

        // base case handle:
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == j) dp[i][j] = 1;
            }
        }

        for(int low=n-1; low>=0; low--)
        {
            for(int high=0; high<n; high++)
            {
                if(low == high) continue;
                
                int ans = INT_MAX;
                // lop over all possible combination of substrings:
                for(int i=low; i<high; i++)
                {
                    int left = dp[low][i];
                    int right = dp[i+1][high];

                    int total = left + right;
                    ans = min(ans, total);
                }

                // if first and last character is same, we can overwrite middle characters so:
                if(s[low] == s[high])
                {
                    ans = ans - 1;
                }

                dp[low][high] = ans;
            }
        }

        return dp[0][n-1];
    }

    int strangePrinter(string s) {
        // return solve(s, 0, s.size()-1);

        // Memorisation:
        // int n = s.size();
        // vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
        // return solve2(s, 0, n-1, dp);

        // Tabulation:
        int n = s.size();
        return solve3(s);
    }
};