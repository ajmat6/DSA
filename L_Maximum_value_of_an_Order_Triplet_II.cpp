class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> prefixMax (nums.size(), 0);
        vector<int> suffixMax (nums.size(), 0);

        prefixMax[0] = nums[0];
        suffixMax[nums.size()-1] = nums[nums.size()-1];

        int leftMax = nums[0];
        int rightMax = nums[nums.size()-1];

        // making prefix max array:
        for(int i=1; i<nums.size(); i++)
        {
            prefixMax[i] = leftMax;

            if(nums[i] > leftMax)
            {
                leftMax = nums[i];
            }
        }

        // making suffix max array
        for(int i=nums.size()-1; i>=0; i--)
        {
            suffixMax[i] = rightMax;

            if(nums[i] > rightMax)
            {
                rightMax = nums[i];
            }
        }

        long long ans = 0;
        for(int i=1; i<nums.size()-1; i++)
        {
            long long temp = (prefixMax[i] - nums[i]) * 1LL * suffixMax[i];

            if(temp > ans) ans = temp;
        }

        return ans;
    }
};