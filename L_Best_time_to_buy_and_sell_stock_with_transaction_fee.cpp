class Solution {
public:
    // Tabulation:
    int solve3(vector<int>& prices, int fee)
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
                    int sellCase = +prices[index] + dp[index+1][0] - fee;
                    int ignore = 0 + dp[index+1][1];

                    profit = max(profit, max(sellCase, ignore));
                }

                dp[index][buy] = profit;
            }
        }

        return dp[0][0];
    }

    // Space Optimisation:
    int solve4(vector<int>& prices, int fee)
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
                    int sellCase = +prices[index] + next[0] -fee;
                    int ignore = 0 + next[1];

                    profit = max(profit, max(sellCase, ignore));
                }

                curr[buy] = profit;
            }

            next = curr;
        }

        return next[0];
    }

    int maxProfit(vector<int>& prices, int fee) {
        // return solve3(prices, fee);

        return solve4(prices, fee);
    }
};