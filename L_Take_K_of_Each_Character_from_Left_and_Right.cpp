class Solution {
public:
    bool check(int& len, string& s, int& k) {
        int low = 0, high = 0;
        vector<int> freq (3);
        for(; high<len; high++) {
            freq[s[high] - 'a']++;
        }
        high--;
        while(true) {
            if(freq[0] >= k && freq[1] >= k && freq[2] >= k) return true;
            low--;
            if(low == -1) low = s.size() - 1;
            freq[s[low] - 'a']++;
            freq[s[high] - 'a']--;
            high--;
            if(high == -1) high = s.size() - 1;
            if(high == s.size() - 2) break;
        }
        return false;
    }
    
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        int n = s.size();
        int low = 3 * k;
        int high = n;

        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(mid, s, k)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};