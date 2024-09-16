class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int high = 0;
        vector<char> freq (256, 0);

        int ans = 0;
        while(high < s.size()) {
            freq[s[high]]++;
            while(freq[s[high]] > 1 && low <= high) {
                freq[s[low]]--;
                low++;
            }
            ans = max(ans, high - low + 1);
            high++;
        }
        return ans;
    }
};