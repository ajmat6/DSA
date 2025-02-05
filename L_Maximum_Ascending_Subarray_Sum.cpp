class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int currSum = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i - 1]) {
                currSum += nums[i];
                ans = max(ans, currSum);
            }
            else currSum = nums[i];
        }
        return max(ans, currSum);
    }
};