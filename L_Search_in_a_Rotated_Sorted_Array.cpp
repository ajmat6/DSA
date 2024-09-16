class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            // find sorted Part and check in it, if it is there in sorted part, move that side else move oppo side:
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]) {
                if(target >= nums[low] && target <= nums[mid]) high = mid - 1;
                else low = mid + 1;
            }
            else if(nums[mid] <= nums[high]) {
                if(target >= nums[mid] && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};