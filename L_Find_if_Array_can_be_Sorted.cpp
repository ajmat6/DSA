class Solution {
public:
    int findBits(int num) {
        int count = 0;
        while(num != 0) {
            num &= (num - 1);
            count += 1;
        }
        return count;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = 0;
        int prevMax = INT_MIN;
        while(high < n) {
            int currMin = INT_MAX;
            int currMax = INT_MIN;
            int currBitCount = findBits(nums[low]);
            while(high < n && findBits(nums[high]) == currBitCount) {
                currMax = max(currMax, nums[high]);
                currMin = min(currMin, nums[high]);
                high++;
            }
            if(currMin < prevMax) return false;
            prevMax = currMax;
            low = high;
        }
        return true;
    }
};