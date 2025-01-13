class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq (26, 0);
        for(auto i: s) freq[i - 'a']++;

        int ans = 0;
        for(auto i: freq) {
            if(i != 0) {
                if(i % 2 == 0) ans += 2;
                else ans += 1;
            }
        }
        return ans;
    }
};