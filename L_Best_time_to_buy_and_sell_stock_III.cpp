class Solution {
public:
    // Recursion: Gives TLE
    int solve(vector<int>& prices, int index, bool buy, int limit)
    {
        if(index == prices.size()) return 0;
        if(limit == 0) return 0;

        int profit = INT_MIN;
        // Buy case:
        if(buy == false)
        {
            int buyCase = -prices[index] + solve(prices, index+1, true, limit);
            int ignore = 0 + solve(prices, index+1, false, limit);

            profit = max(profit, max(buyCase, ignore));
        }

        // Sell Case:
        if(buy == true)
        {
            int sellCase = +prices[index] + solve(prices, index+1, false, limit-1);
            int ignore = 0 + solve(prices, index+1, true, limit);

            profit = max(profit, max(sellCase, ignore));
        }

        return profit;
    }

    // Memorisation:
    int solve2(vector<int>& prices, int index, int buy, int limit, vector<vector<vector<int>>>& dp)
    {
        if(index == prices.size()) return 0;
        if(limit == 0) return 0;

        // check for dp:
        if(dp[index][buy][limit] != -1) return dp[index][buy][limit];

        int profit = INT_MIN;
        // Buy case:
        if(buy != 1)
        {
            int buyCase = -prices[index] + solve2(prices, index+1, 1, limit, dp);
            int ignore = 0 + solve2(prices, index+1, 0, limit, dp);

            profit = max(profit, max(buyCase, ignore));
        }

        // Sell Case:
        else
        {
            int sellCase = +prices[index] + solve2(prices, index+1, 0, limit-1, dp);
            int ignore = 0 + solve2(prices, index+1, 1, limit, dp);

            profit = max(profit, max(sellCase, ignore));
        }

        dp[index][buy][limit] = profit;

        return profit;
    }

    // Tabulation:
    int solve3(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n+1,  vector<vector<int>> (2, vector<int> (3, 0)));

        // Handling rest of the recursive cases:
        for(int index=n-1; index>=0; index--)
        {
            for(int buy=1; buy>=0; buy--)
            {

                for(int limit=1; limit<=2; limit++)
                {
                    int profit = INT_MIN;
                    // Buy case:
                    if(buy != 1)
                    {
                        int buyCase = -prices[index] + dp[index+1][1][limit];
                        int ignore = 0 + dp[index+1][0][limit];

                        profit = max(profit, max(buyCase, ignore));
                    }

                    // Sell Case:
                    else
                    {
                        int sellCase = +prices[index] + dp[index+1][0][limit-1];
                        int ignore = 0 + dp[index+1][1][limit];

                        profit = max(profit, max(sellCase, ignore));
                    }

                    dp[index][buy][limit] = profit;
                }
            }
        }

        return dp[0][0][2];
    }

    // Space Optimisation: TC = O(n) and SC = O
    int solve4(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> curr (2, vector<int> (3, 0));
        vector<vector<int>> next (2, vector<int> (3, 0));

        // Handling rest of the recursive cases:
        for(int index=n-1; index>=0; index--)
        {
            for(int buy=1; buy>=0; buy--)
            {
                for(int limit=1; limit<=2; limit++)
                {
                    int profit = INT_MIN;
                    // Buy case:
                    if(buy != 1)
                    {
                        int buyCase = -prices[index] + next[1][limit];
                        int ignore = 0 + next[0][limit];

                        profit = max(profit, max(buyCase, ignore));
                    }

                    // Sell Case:
                    else
                    {
                        int sellCase = +prices[index] + next[0][limit-1];
                        int ignore = 0 + next[1][limit];

                        profit = max(profit, max(sellCase, ignore));
                    }

                    curr[buy][limit] = profit;
                }
            }

            next = curr;
        }

        return next[0][2];
    }

    int maxProfit(vector<int>& prices) {
        // return solve(prices, 0, 0, 2);

        // Memorisation:
        // vector<vector<vector<int>>> dp (prices.size(),  vector<vector<int>> (2, vector<int> (3, -1)));
        // return solve2(prices, 0, 0, 2, dp);

        // Tabulation:
        // return solve3(prices);

        // Space Optimisation:
        return solve4(prices);
    }
};