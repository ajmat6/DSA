class Solution {
public:
    // Recursion: Gives TLE
    int solve(vector<int>& prices, int index, bool buy)
    {
        if(index == prices.size()) return 0;

        int profit = INT_MIN;
        // Buy case:
        if(buy == false)
        {
            int buyCase = -prices[index] + solve(prices, index+1, true);
            int ignore = 0 + solve(prices, index+1, false);

            profit = max(profit, max(buyCase, ignore));
        }

        // Sell Case:
        if(buy == true)
        {
            int sellCase = +prices[index] + solve(prices, index+1, false);
            int ignore = 0 + solve(prices, index+1, true);

            profit = max(profit, max(sellCase, ignore));
        }

        return profit;
    }

    // Memorisation:
    int solve2(vector<int>& prices, int index, int buy, vector<vector<int>>& dp)
    {
        if(index == prices.size()) return 0;

        // check for dp:
        if(dp[index][buy] != -1) return dp[index][buy];

        int profit = INT_MIN;
        // Buy case:
        if(buy != 1)
        {
            int buyCase = -prices[index] + solve2(prices, index+1, 1, dp);
            int ignore = 0 + solve2(prices, index+1, 0, dp);

            profit = max(profit, max(buyCase, ignore));
        }

        // Sell Case:
        else
        {
            int sellCase = +prices[index] + solve2(prices, index+1, 0, dp);
            int ignore = 0 + solve2(prices, index+1, 1, dp);

            profit = max(profit, max(sellCase, ignore));
        }

        dp[index][buy] = profit;

        return profit;
    }

    // Tabulation:
    int solve3(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp (n+1, vector<int> (2, -1));

        // Handling base case:
        dp[n][0] = 0;
        dp[n][1] = 0;

        // Handling rest of the recursive cases:
        for(int index=n-1; index>=0; index--)
        {
            for(int buy=1; buy>=0; buy--)
            {
                int profit = INT_MIN;
                // Buy case:
                if(buy != 1)
                {
                    int buyCase = -prices[index] + dp[index+1][1];
                    int ignore = 0 + dp[index+1][0];

                    profit = max(profit, max(buyCase, ignore));
                }

                // Sell Case:
                else
                {
                    int sellCase = +prices[index] + dp[index+1][0];
                    int ignore = 0 + dp[index+1][1];

                    profit = max(profit, max(sellCase, ignore));
                }

                dp[index][buy] = profit;
            }
        }

        return dp[0][0];
    }

    // Space Optimisation: TC = O(n) and SC = O
    int solve4(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> curr (2, -1);
        vector<int> next (2, -1);

        // Handling base case:
        next[0] = 0;
        next[1] = 0;

        // Handling rest of the recursive cases:
        for(int index=n-1; index>=0; index--)
        {
            for(int buy=1; buy>=0; buy--)
            {
                int profit = INT_MIN;
                // Buy case:
                if(buy != 1)
                {
                    int buyCase = -prices[index] + next[1];
                    int ignore = 0 + next[0];

                    profit = max(profit, max(buyCase, ignore));
                }

                // Sell Case:
                else
                {
                    int sellCase = +prices[index] + next[0];
                    int ignore = 0 + next[1];

                    profit = max(profit, max(sellCase, ignore));
                }

                curr[buy] = profit;
            }

            next = curr;
        }

        return next[0];
    }

    int maxProfit(vector<int>& prices) {
        // return solve(prices, 0, false);

        // Memorisation:
        // vector<vector<int>> dp (prices.size(), vector<int> (2, -1));
        // return solve2(prices, 0, 0, dp);

        // Tabulation:
        // return solve3(prices);

        // Space Optimisation:
        return solve4(prices);
    }
};