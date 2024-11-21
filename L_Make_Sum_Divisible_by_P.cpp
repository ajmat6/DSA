#define ll long long
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        ll sum = 0;
        for(auto i: nums) sum += i;
        if(sum % p == 0) return 0;
        
        ll rem = sum % p;
        unordered_map<ll, ll> mp;
        mp[0] = -1;

        int ans = nums.size();
        ll currSum = 0;
        for(int i=0; i<nums.size(); i++) {
            currSum += nums[i];
            ll check = (currSum % p - rem + p) % p;
            if(mp.count(check)) ans = min(ans, int(i - mp[check]));
            mp[currSum % p] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};