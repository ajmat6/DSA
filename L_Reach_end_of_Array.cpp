class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int curr = 1;
        int prev = 0;
        long long ans = 0;
        while(curr < nums.size()) {
            if(nums[curr] > nums[prev]) {
                ans += (curr - prev) * 1LL * nums[prev];
                prev = curr;
            }
            curr++;
        }

        if(prev != nums.size() - 1) {
            ans += (nums.size() - 1 - prev) * 1LL * nums[prev];
        }

        return ans;
    }
};