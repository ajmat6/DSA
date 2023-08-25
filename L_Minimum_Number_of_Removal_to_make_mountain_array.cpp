class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> dp1(nums.size(), 1);
        vector<int> dp2(nums.size(), 1);

        // to find longest incresing subsequnce from left side:
        for(int curr=0; curr<nums.size(); curr++)
        {
            for(int prev=0; prev<curr; prev++)
            {
                if(nums[curr] > nums[prev] && 1 + dp1[prev] > dp1[curr])
                {
                    dp1[curr] = 1 + dp1[prev];
                }
            }
        }

        // to find longest incresing subsequnce from right side:
        for(int curr=nums.size()-1; curr>=0; curr--)
        {
            for(int prev=nums.size()-1; prev>curr; prev--)
            {
                if(nums[curr] > nums[prev] && 1 + dp2[prev] > dp2[curr])
                {
                    dp2[curr] = 1 + dp2[prev];
                }
            }
        }

        // finding mountain array elements for each index:
        int maxiElementsMountain = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            if(dp1[i] == 1 || dp2[i] == 1) continue; // as it is not adding to the mountain formation:
            int temp = dp1[i] + dp2[i] - 1;
            maxiElementsMountain = max(maxiElementsMountain, temp);
        }

        return nums.size() - maxiElementsMountain;
    }
};