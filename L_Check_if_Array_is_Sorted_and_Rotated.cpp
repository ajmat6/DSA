class Solution {
public:
    bool check(vector<int>& nums) {
        int first = 1, n = nums.size();
        for(int i=1; i<n; i++) {
            if(nums[i] < nums[i - 1]) {
                if(first) first = 0;
                else return false;
            }
        }
        if(first) return true;
        return nums[0] >= nums[n - 1];
    }
};