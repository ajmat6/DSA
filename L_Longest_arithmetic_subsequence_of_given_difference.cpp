class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        unordered_map<int, int> dp;

        for(int i=0; i<arr.size(); i++)
        {
            int diff = arr[i] - difference;
            int diffCount = 0;

            // check in dp:
            if(dp.count(diff) > 0)
            {
                diffCount = dp[diff];
            }

            // storing in dp:
            dp[arr[i]] = 1 + diffCount;

            // updating ans;
            ans = max(ans, dp[arr[i]]);
        }

        return ans;
    }
};