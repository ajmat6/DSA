class Solution {
public:
    // Memorisation:
    int solve(int n, vector<int>& dp)
    {
        if(n<=1) return 1;

        if(dp[n] != -1) return dp[n];

        // storing the ans:
        int ans = 0;

        // taking each value as a head:
        for(int i=1; i<=n; i++)
        {
            ans += solve(i-1, dp) * solve(n-i, dp);
        }

        dp[n] = ans;

        return ans;
    }

    // Tabulation:
    int solve2(int n)
    {
        vector<int> dp(n+1, 0);

        // Base Case handle:
        dp[0] = dp[1] = 1;

        // Handling recursive cases:
        int ans = 0;

        // for no of nodes:
        for(int i=2; i<=n; i++)
        {
            // taking each value as head for the no of nodes:
            for(int j=1; j<=i; j++)
            {
                dp[i] +=  dp[j-1] * dp[i-j];
            }
        }

        return dp[n];
    }

    int numTrees(int n) {
        // vector<int> dp (n+1, -1);
        // return solve(n, dp);

        // Tabulation:
        return solve2(n);
    }
};