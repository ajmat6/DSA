class Solution {
public:
    bool isNum(char ch) {
        if(ch >= '0' && ch <= '9') return true;
        return false;
    }

    int myAtoi(string s) {
        int index = 0;
        int n = s.size();
        bool neg = false;

        while(index < n && s[index] == ' ') index++;
        if(index == n) return 0;

        if(s[index] == '-') {
            neg = true;
            index++;
        }
        else if(s[index] == '+') index++;
        
        long long ans = 0;
        while(index < n && isNum(s[index])) {
            ans = ans * 10 + (s[index] - '0');
            if(ans > INT_MAX && neg) return INT_MIN;
            else if(ans >= INT_MAX && !neg) return INT_MAX;
            index++;
        }

        return neg ? ans * -1 : ans;
    }
};