typedef long long ll;
class Solution {
public:
    long long solve(vector<int>& nums, int k, int index, int took, vector<vector<vector<long long>>>& dp) {
        if(k == 0) return 0;
        if(index == nums.size()) {
            if(k == 1 && took) return 0; // edge case
            else return -1e15;
        } 

        if(dp[index][k][took] != INT_MIN) return dp[index][k][took];

        ll ans = -1e15;

        // not taking the current index:
        ll notTake;
        if(took == 0) ans = max(ans, solve(nums, k, index + 1, 0, dp));
        else ans = max(ans, solve(nums, k - 1, index, 0, dp)); // breaking the continuity (edge case)

        // take case
        ll take = solve(nums, k, index + 1, 1, dp);
        ll sign = (k % 2 == 0) ? -1 : 1;
        ans = max(ans, sign * k * 1LL * nums[index] + take);

        return dp[index][k][took] = ans;
    }

    long long maximumStrength(vector<int>& nums, int k) {
        vector<vector<vector<long long>>> dp (nums.size() + 1, vector<vector<long long>> (k + 1, vector<ll> (2, INT_MIN)));
        return solve(nums, k, 0, 0, dp);
    }
};