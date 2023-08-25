class Solution {
public:
    int solve(int low, int high)
    {
        if(low >= high) return 0;

        int maxi = INT_MAX;
        for(int i=low; i<=high; i++)
        {
            maxi = min(maxi, i+max(solve(low, i-1), solve(i+1, high)));
        }

        return maxi;
    }

    int solve2(int low, int high, vector<vector<int>>& dp)
    {
        if(low >= high) return 0;

        // checking for dp:
        if(dp[low][high] != -1) return dp[low][high];

        int maxi = INT_MAX;
        for(int i=low; i<=high; i++)
        {
            maxi = min(maxi, i+max(solve2(low, i-1, dp), solve2(i+1, high, dp)));
        }

        // storing in dp:
        dp[low][high] = maxi;

        return maxi;
    }

    // Tabulation:
    int solve3(int n)
    {
        vector<vector<int>> dp (n+2, vector<int> (n+2, 0));

        for(int low=n; low>=1; low--)
        {
            for(int high=low; high<=n; high++)
            {
                if(low == high) continue;

                else
                {
                    int maxi = INT_MAX;
                    for(int i=low; i<=high; i++)
                    {
                        maxi = min(maxi, i+max(dp[low][i-1], dp[i+1][high]));
                    }

                    dp[low][high] = maxi;
                }
            }
        }


        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        // return solve(1, n);

        // Memorisation:
        // vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
        // return solve2(1, n, dp);

        // Tabulation:
        return solve3(n);
    }
};