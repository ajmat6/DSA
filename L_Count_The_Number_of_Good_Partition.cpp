class Solution {
public:
    int mod = 1000000007;
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp; int n = nums.size();

        // first and last index of each element in nums:
        for(int i=0; i<n; i++)
        {
            if(mp.find(nums[i]) == mp.end()) mp[nums[i]] = {i, i};
            else mp[nums[i]].second = i;
        }

        // find non overlapping intervals:
        int lastIndex = -1;
        int intervals = 0;
        for(auto &i: nums)
        {
            if(mp[i].first == lastIndex + 1)
            {
                intervals++;
                lastIndex = mp[i].second;
            }
            else lastIndex = max(lastIndex, mp[i].second);
        }

        int power = intervals - 1;
        int a = 2;
        int ans = 1;
        while(power != 0)
        {
            if(power % 2 == 1) ans = (ans * 1LL * a) % mod;
            a = (a * 1LL * a) % mod;
            power /= 2;
        }

        return ans;
    }
};