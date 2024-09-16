class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n - 2;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            else if(nums[mid] > nums[mid - 1]) low = mid + 1;
            else if(nums[mid] < nums[mid - 1]) high = mid - 1;
            else high = mid - 1; // cases like 2, 1, 3 -> when there is dip and here mid is 1. In this case you can go in any direction
        }
        return nums[0] >= nums[n - 1] ? 0 : n - 1; // will handle case when n is 1 and if peak element lies at 0th and last index
    }
};