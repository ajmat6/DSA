class Solution {
public:
    long long minimumSteps(string s) {
        int index = 0, count = 0, n = s.size();
        long long ans = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '1') count++;
            else ans += count;
        }
        return ans;
    }
};