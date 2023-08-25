class Solution {
public: 
    int solve(int& totalAmount, vector<int>& coins, int index, int amount)
    {
        if(index == coins.size())
        {
            if(amount == totalAmount) return 1;
            else return 0;
        }
        if(amount == totalAmount) return 1;

        int Take = 0;
        // take present index coin:
        if(amount + coins[index] <= totalAmount)
        {
            Take = solve(totalAmount, coins, index, amount+coins[index]);
        }

        // not taking present index coin:
        int notTake = solve(totalAmount, coins, index+1, amount);

        int ans = Take + notTake;
        return ans;
    }

    int solveMem(int& totalAmount, vector<int>& coins, int index, int amount, vector<vector<int>>& dp)
    {
        if(index == coins.size())
        {
            if(amount == totalAmount) return 1;
            else return 0;
        }
        if(amount == totalAmount) return 1;

        // check for dp:
        if(dp[index][amount] != -1) return dp[index][amount];

        int Take = 0;
        // take present index coin:
        if(amount + coins[index] <= totalAmount)
        {
            Take = solveMem(totalAmount, coins, index, amount+coins[index], dp);
        }

        // not taking present index coin:
        int notTake = solveMem(totalAmount, coins, index+1, amount, dp);

        int ans = Take + notTake;

        // storing in dp:
        dp[index][amount] = ans;
        return ans;
    }

    // Tabulation:
    int solveTab(int& totalAmount, vector<int>& coins)
    {
        vector<vector<int>> dp (coins.size()+1, vector<int> (totalAmount+1, 0));

        // Handling base case:
        for(int i=0; i<dp.size(); i++)
        {
            dp[i][totalAmount] = 1;
        }

        for(int index=coins.size()-1; index>=0; index--)
        {
            for(int amount=totalAmount; amount>=0; amount--)
            {
                int Take = 0;
                // take present index coin:
                if(amount + coins[index] <= totalAmount)
                {
                    Take = dp[index][amount+coins[index]];
                }

                // not taking present index coin:
                int notTake = dp[index+1][amount];

                int ans = Take + notTake;

                // storing in dp:
                dp[index][amount] = ans;
            }
        }

        return dp[0][0];
    }

    // Space Optimisation:
    int solveSpaceOpt(int& totalAmount, vector<int>& coins)
    {
        vector<int> curr (totalAmount+1, 0);
        vector<int> next (totalAmount+1, 0);

        // Handling base case:
        curr[totalAmount] = 1;
        next[totalAmount] = 1;

        for(int index=coins.size()-1; index>=0; index--)
        {
            for(int amount=totalAmount; amount>=0; amount--)
            {
                int Take = 0;
                // take present index coin:
                if(amount + coins[index] <= totalAmount)
                {
                    Take = curr[amount+coins[index]];
                }

                // not taking present index coin:
                int notTake = next[amount];

                int ans = Take + notTake;

                // storing in dp:
                curr[amount] = ans;
            }
            next = curr;
        }

        return curr[0];
    }

    int change(int amount, vector<int>& coins) {
        // return solve(amount, coins, 0, 0);

        // Memoristion:
        // vector<vector<int>> dp (coins.size(), vector<int> (amount+1, -1));
        // return solveMem(amount, coins, 0, 0, dp);

        // Tabulation:
        // return solveTab(amount, coins);

        // Space Optimisation:
        return solveTab(amount, coins);
    }
};