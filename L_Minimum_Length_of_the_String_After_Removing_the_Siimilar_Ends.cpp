class Solution {
public:
    int minimumLength(string s) {
        int low = 0;
        int high = s.size() - 1;

        while(low < high) {
            if(s[low] != s[high]) break;
            else {
                char first = s[low];
                char second = s[high];
                while(low < high && s[low] == first) low++;
                while(high >= 0 && s[high] == second) high--;
            }
        }

        if(high < low) return 0;
        return high - low + 1;
    }
};