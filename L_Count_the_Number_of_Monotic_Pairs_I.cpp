class Solution {
public:
    int mod = 1000000007;
    int solve(vector<int>& nums, int index, int prev0, int prev1, vector<vector<vector<int>>>& dp) {
        if(index == nums.size()) return 1;

        if(dp[index][prev0][prev1] != -1) return dp[index][prev0][prev1];

        int ans = 0;
        for(int i=prev0; i<=nums[index]; i++) {
            int rem = nums[index] - i;
            if(rem <= prev1) ans = (long long)(ans +  solve(nums, index + 1, i, rem, dp)) % mod;
        }

        return dp[index][prev0][prev1] = ans;
    }
    int countOfPairs(vector<int>& nums) {
        vector<vector<vector<int>>> dp (nums.size() + 1,  vector<vector<int>> (51, vector<int> (51, -1)));
        return solve(nums, 0, 0, nums[0], dp);
    }
};