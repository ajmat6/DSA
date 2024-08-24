class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // with previous count: storing rem values with its frequecies
        // unordered_map<int, int> mp;
        // mp[0] = 1; int ans = 0, prev = 0, sum = 0; int prevCount = 1;
        // for(auto i: nums) {
        //     sum += i;
        //     if(mp.find(sum % k) != mp.end() && (prev != sum % k || (prev == sum % k && prevCount > 1))) return true;
        //     else {
        //         mp[sum % k]++;
        //         if(sum % k == prev) prevCount++;
        //         else {
        //             prev = sum % k;
        //             prevCount = 1;
        //         }
        //     }
        // }
        // return false;


        // without previous count: storing rem values with its index:
        unordered_map<int, int> mp;
        mp[0] = -1; int ans = 0, sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            if(mp.find(sum % k) != mp.end()) {
                if(i - mp[sum % k] >= 2) return true;
            } 
            else mp[sum % k] = i;
        }
        return false;
    }
};