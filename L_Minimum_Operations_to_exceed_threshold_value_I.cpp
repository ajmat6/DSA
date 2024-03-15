class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for(auto i: nums) {
            if(i < k) count++;
        }
        return count;
    }
};