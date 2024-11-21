class Solution {
public:
    int dfs(vector<int>& nums, int index, int& maxOr, int currOr, vector<vector<int>>& dp) {
        if(index == nums.size()) {
            if(currOr == maxOr) return 1;
            return 0;
        }

        if(dp[index][currOr] != -1) return dp[index][currOr];

        int take = dfs(nums, index + 1, maxOr, currOr | nums[index], dp);
        int notTake =  dfs(nums, index + 1, maxOr, currOr, dp);
        return dp[index][currOr] = take + notTake;
    }

    int tab(vector<int>& nums, int& maxOr) {
        int n = nums.size();
        vector<vector<int>> dp (n + 1, vector<int> (maxOr + 1, 0));
        dp[n][maxOr] = 1;

        for(int index=n-1; index>=0; index--) {
            for(int currOr=0; currOr<=maxOr; currOr++) {
                int take = 0;
                if((currOr | nums[index]) <= maxOr) take = dp[index + 1][(currOr | nums[index])];
                int notTake =  dp[index + 1][currOr];
                dp[index][currOr] = take + notTake;
            }
        }
        return dp[0][0];
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(auto i: nums) maxOr |= i;
        // vector<vector<int>> dp (nums.size() + 1, vector<int> (maxOr + 1, -1));
        // return dfs(nums, 0, maxOr, 0, dp);

        return tab(nums, maxOr);
    }
};