class Solution {
public:
    // Kadane's Algorithm:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;

        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            maxSum = max(maxSum, sum);

            // set sum = 0 if sum is negative:
            if(sum < 0) sum = 0;
        }

        return maxSum;
    }
};