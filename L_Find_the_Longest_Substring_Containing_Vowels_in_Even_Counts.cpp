class Solution {
public:
    int findTheLongestSubstring(string s) {
        // storing no of times a, e, i, o, u are occuring in s with odd as 1 and even as 0:
        unordered_map<int, int> mp;
        mp[0] = -1;

        int ans = 0;
        int currXor = 0;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') currXor ^= (1 << (s[i] - 'a'));
            if(mp.count(currXor)) ans = max(ans, i - mp[currXor]);
            else mp[currXor] = i;
        }
        return ans;
    }
};