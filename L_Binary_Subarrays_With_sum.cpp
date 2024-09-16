class Solution {
public:
    int findTotal(vector<int>& nums, int goal) {
        int ans = 0;
        int low  = 0;
        int high = 0;
        int sum = 0;
        while(high < nums.size()) {
            sum += nums[high];
            while(sum > goal && low <= high) {
                sum -= nums[low];
                low++;
            }

            if(low <= high) ans += high - low + 1;
            high++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // like subarray sum equals k: using hashmap: time is n and space is n:
        // unordered_map<int, int> mp; mp[0] = 1;
        // int sum = 0, ans = 0;
        // for(auto i: nums) {
        //     sum += i;
        //     if(sum >= goal && mp.find(sum - goal) != mp.end()) ans += mp[sum - goal];
        //     mp[sum]++;
        // }
        // return ans;



        // using two pointers: It only works for positives or zeros in array (not for negatives): n time and constant space
        // find no of subarrays where sum is less than or eqal to k and subtract subarrays where sum is less than k -> gives you no of subarrays where sum is equal to k:
        return findTotal(nums, goal) - findTotal(nums, goal - 1);
    }
};