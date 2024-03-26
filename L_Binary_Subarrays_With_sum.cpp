class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // like subarray sum equals k:
        // unordered_map<int, int> mp; mp[0] = 1;
        // int sum = 0; int ans = 0;
        // for(auto i: nums) {
        //     sum += i;
        //     if(sum >= goal && mp.find(sum - goal) != mp.end()) ans += mp[sum - goal];
        //     mp[sum]++;
        // }

        // return ans;
    }
};