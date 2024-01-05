class Solution {
public:
    int solve(vector<int>& cost, vector<int>& time, int index, int total,   vector<vector<int>>& dp)
    {
        if(total <= 0) return 0;
        if(index == cost.size()) return 1e9;

        if(dp[index][total] != -1) return dp[index][total];

        int take = cost[index] + solve(cost, time, index + 1, total - 1 - time[index], dp);
        int notTake = 0 + solve(cost, time, index + 1, total, dp);

        int ans = min(take, notTake);
        return dp[index][total] = ans;
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        // intially there are cost.size() walls to paint:
        // vector<vector<int>> dp (cost.size() + 1, vector<int> (cost.size() + 1, -1));
        // return solve(cost, time, 0, cost.size(), dp);

        return solve2(cost, time);
    }
};