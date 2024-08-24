class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int low = 0, high = 0, maxFreq = 0, ans = 0;
        while(high < nums.size()) {
            mp[nums[high]]++;
            maxFreq = max(maxFreq, mp[nums[high]]);

            while(maxFreq > k) {
                mp[nums[low]]--;
                if(nums[low] == nums[high]) maxFreq -= 1;
                low++;
            }

            ans = max(ans, high - low + 1);
            high++;
        }
        return ans;
    }
};