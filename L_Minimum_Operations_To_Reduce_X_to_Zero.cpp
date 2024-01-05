class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for(auto i: nums) totalSum += i;

        // subtracting x from totalsum to find to make new target of remaining values:
        int target = totalSum - x;

        // if all the elements would make up x in array:
        if(target == 0) return nums.size();

        int left = 0;
        int currSum = 0;
        int ans = 0;
        
        for(int right=0; right<nums.size(); right++)
        {
            currSum +=  nums[right];

            while(left <= right && currSum > target)
            {
                currSum -= nums[left];
                left++;
            }

            if(currSum == target)
            {
                ans = max(ans, right - left + 1);
            }
        }

        return ans ? nums.size() - ans : -1;
    }
};