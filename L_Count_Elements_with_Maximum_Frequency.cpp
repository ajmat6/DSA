class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxFreq = INT_MIN;
        for(auto i: nums) {
            int count = mp[i];
            if(count + 1 > maxFreq) maxFreq = count + 1;
            mp[i]++;
        }
        int ans = 0;
        for(auto i: mp) {
            if(i.second == maxFreq) ans += i.second;
        }
        return ans;
    }
};