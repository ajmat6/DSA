class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long total = ((n - 1) * 1LL * n) / 2;
        for(int i=0; i<n; i++) total -= mp[nums[i] - i]++;
        return total;
    }
};