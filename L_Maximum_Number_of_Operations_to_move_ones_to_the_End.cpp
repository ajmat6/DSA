class Solution {
public:
    int maxOperations(string s) {
        int index = 0, count = 0, ans = 0;
        while(index < s.size() && s[index] == '0') index++;
        while(index < s.size()) {
            while(index < s.size() && s[index] == '1') {
                index++;
                count++;
            }
            bool zero = false;
            while(index < s.size() && s[index] == '0') {
                index++;
                zero = true;
            }
            if(zero) ans += count;
        }
        return ans;
    }
};