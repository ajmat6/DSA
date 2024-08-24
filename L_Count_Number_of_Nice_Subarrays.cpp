class Solution {
public:
    int solve(vector<int>& nums, int low, int high , int k) {
        int count = 0; int ans = 0;
        while(low <= high && high < nums.size()) {
            count += nums[high];
            while(low <= high && count > k) {
                count -= nums[low];
                low++;
            }
            ans += high - low + 1;
            high++;
        }
        cout << ans;
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        // pre computation: converting even nos to 0 and odd nos to 1:
        for(auto &i: nums) {
            if(i % 2 == 0) i = 0;
            else i = 1;
        }

        // using hashmap: O(n) space and time:
        // unordered_map<int, int> mp;
        // mp[0] = 1;
        // int count = 0; int ans = 0;
        // for(auto i: nums) {
        //     count += i;
        //     if(count >= k && mp.find(count - k) != mp.end()) ans += mp[count - k];
        //     mp[count]++;
        // }
        // return ans;    

        // using two pointers: O(n) time and O(1) space:
        return solve(nums, 0, 0, k) - solve(nums, 0, 0, k - 1);    
    }
};