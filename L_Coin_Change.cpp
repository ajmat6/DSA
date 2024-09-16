class Solution {
public:
    // int dfs(vector<int>& coins, int amount, int index, vector<vector<int>>& dp) {
    //     if(index == coins.size()) {
    //         if(amount == 0) return 0;
    //         return 1e9;
    //     }

    //     if(dp[index][amount] != -1) return dp[index][amount];

    //     // at current index you can take 0, 1, 2.. till amount / coins is an integer:

    //     // not Take:
    //     int notTake = dfs(coins, amount, index + 1, dp);
    //     int take = INT_MAX;
    //     if(amount >= coins[index]) {
    //         int maxTake = amount / coins[index];
    //         for(int i=1; i<=maxTake; i++) {
    //             take = min(take, i + dfs(coins, amount - (coins[index] * i), index + 1, dp));
    //         }
    //     }

    //     return dp[index][amount] = min(take, notTake);
    // }

    int dfs(vector<int>& coins, int amount, vector<int>& dp) {
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            int dfsCall = dfs(coins, amount - coins[i], dp);
            if(dfsCall != INT_MAX) ans = min(ans, 1 + dfsCall);
        }

        return dp[amount] = ans;
    }

    int tabulation(vector<int>& coins, int money) {
        vector<int> dp(money + 1, 0);
        for(int amount=1; amount<=money; amount++) {
            int ans = INT_MAX;
            for(int i=0; i<coins.size(); i++) {
                if(amount - coins[i] >= 0) {
                    int dfsCall = dp[amount - coins[i]];
                    if(dfsCall != INT_MAX) ans = min(ans, 1 + dfsCall);
                }
            }

            dp[amount] = ans;
        }
        return dp[money];
    }

    int coinChange(vector<int>& coins, int amount) {
        // this has time of nlogn + n * amount * amount: very high but excepted
        // sort(coins.begin(), coins.end());
        // vector<vector<int>> dp (13, vector<int> (amount + 1, -1));
        // int coinss = dfs(coins, amount, 0, dp);
        // return coinss == 1e9 ? -1 : coinss;


        // vector<int> dp (amount + 1, -1);
        // int ans = dfs(coins, amount, dp);
        // return ans == INT_MAX ? -1 : ans;


        int ans = tabulation(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};