class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mp;
        for(auto &i: s) {
            mp[i]++;
        }

        for(auto &i: t) {
            if(mp.find(i) != mp.end() && mp[i] != 0) mp[i]--;
        }

        int ans = 0;
        for(auto i: mp) ans += i.second;
        return ans;
    }
};