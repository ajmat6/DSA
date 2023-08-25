class Solution {
public:
    // Recursion: Gives TLE
    int solve(vector<int>& prices, int operationNo, int k, int index)
    {
        if(index == prices.size()) return 0;
        if(operationNo > 2*k) return 0;

        int profit = INT_MIN;

        // if operation no is even means you have to buy:
        if(operationNo % 2 == 0)
        {
            int buyCase = -prices[index] + solve(prices, operationNo+1, k, index+1);
            int ignore = 0 + solve(prices, operationNo, k, index+1);

            profit = max(profit, max(buyCase, ignore));
        }

        // if operation no is odd means you have to sell:
        else
        {
            int sellCase = +prices[index] + solve(prices, operationNo+1, k, index+1);
            int ignore = 0 + solve(prices, operationNo, k, index+1);

            profit = max(profit, max(sellCase, ignore));
        }

        return profit;
    }

    // Memorisation:
    int solve2(vector<int>& prices, int operationNo, int k, int index, vector<vector<int>>& dp)
    {
        if(index == prices.size()) return 0;
        if(operationNo > 2*k) return 0;

        // checking for dp:
        if(dp[index][operationNo] != -1) return dp[index][operationNo];

        int profit = INT_MIN;

        // if operation no is even means you have to buy:
        if(operationNo % 2 == 0)
        {
            int buyCase = -prices[index] + solve2(prices, operationNo+1, k, index+1, dp);
            int ignore = 0 + solve2(prices, operationNo, k, index+1, dp);

            profit = max(profit, max(buyCase, ignore));
        }

        // if operation no is odd means you have to sell:
        else
        {
            int sellCase = +prices[index] + solve2(prices, operationNo+1, k, index+1, dp);
            int ignore = 0 + solve2(prices, operationNo, k, index+1, dp);

            profit = max(profit, max(sellCase, ignore));
        }

        // storing in dp:
        dp[index][operationNo] = profit;

        return profit;
    }

    // Tabulation:
    int solve3(vector<int>& prices, int k)
    {
        vector<vector<int>> dp (prices.size()+1, vector<int> (2*k+1, 0));

        for(int index=prices.size()-1; index>=0; index--)
        {
            for(int operationNo=2*k-1; operationNo>=0; operationNo--)
            {
                int profit = INT_MIN;

                // if operation no is even means you have to buy:
                if(operationNo % 2 == 0)
                {
                    int buyCase = -prices[index] + dp[index+1][operationNo+1];
                    int ignore = 0 + dp[index+1][operationNo];

                    profit = max(profit, max(buyCase, ignore));
                }

                // if operation no is odd means you have to sell:
                else
                {
                    int sellCase = +prices[index] + dp[index+1][operationNo+1];
                    int ignore = 0 + dp[index+1][operationNo];

                    profit = max(profit, max(sellCase, ignore));
                }

                // storing in dp:
                dp[index][operationNo] = profit;
            }
        }

        return dp[0][0];
    }

    // Space Optimisation:
    int solve4(vector<int>& prices, int k)
    {
        vector<int> curr (2*k+1, 0);
        vector<int> next (2*k+1, 0);

        for(int index=prices.size()-1; index>=0; index--)
        {
            for(int operationNo=2*k-1; operationNo>=0; operationNo--)
            {
                int profit = INT_MIN;

                // if operation no is even means you have to buy:
                if(operationNo % 2 == 0)
                {
                    int buyCase = -prices[index] + next[operationNo+1];
                    int ignore = 0 + next[operationNo];

                    profit = max(profit, max(buyCase, ignore));
                }

                // if operation no is odd means you have to sell:
                else
                {
                    int sellCase = +prices[index] + next[operationNo+1];
                    int ignore = 0 + next[operationNo];

                    profit = max(profit, max(sellCase, ignore));
                }

                // storing in dp:
                curr[operationNo] = profit;
            }
            next = curr;
        }

        return next[0];
    }

    int maxProfit(int k, vector<int>& prices) {
        // return solve(prices, 0, k, 0);

        // Memorisation:
        // vector<vector<int>> dp (prices.size(), vector<int> (2*k+1, -1));
        // return solve2(prices, 0, k, 0, dp);

        // Tabulation:
        // return solve3(prices, k);

        // Space optimisation:
        return solve4(prices, k);
    }
};