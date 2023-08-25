class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp (nums.size(), 1);
        vector<int> count (nums.size(), 1);
        int maxi = INT_MIN;

        for(int curr=0; curr<nums.size(); curr++)
        {
            for(int prev=0; prev<curr; prev++)
            {
                if(nums[prev] < nums[curr] && 1 + dp[prev] > dp[curr])
                {
                    dp[curr] = 1 + dp[prev];

                    // inheriting the no of longest subsequence:
                    count[curr] = count[prev];
                }

                // sum longest subsequnce again means there is another longest subsequnce:
                else if(nums[prev] < nums[curr] && 1 + dp[prev] == dp[curr])
                {
                    count[curr] += count[prev];
                }
            }

            maxi = max(maxi, dp[curr]);
        }

        // checking for no of longestr increasing subsequnce:
        int TotalCount = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(dp[i] == maxi) TotalCount += count[i];
        }

        return TotalCount;
    }
};