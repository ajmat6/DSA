class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans = 0;
        unordered_map<char, long long> mp;
        for(auto i: s) {
            if(i == c) {
                ans += 1 + mp[c];
                mp[c]++;
            }
        }
        
        return ans;
    }
};