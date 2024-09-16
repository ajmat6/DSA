class Solution {
public:
    long long getPalindrome(long long leftPart, bool odd) {
        long long result = leftPart;
        if(odd) leftPart /= 10; // removing the middle elemnt in case of odd

        while(leftPart != 0) {
            result = result * 10 + leftPart % 10;
            leftPart /= 10;
        }

        return result;
    }

    string nearestPalindromic(string s) {
        int n = s.size();
        bool odd = n % 2 == 1 ? true : false;
        string left = s.substr(0, n / 2);
        if(odd) left += s[n / 2];
        long long leftPart = stol(left);
        set<long long> st;
        st.insert(getPalindrome(leftPart, odd)); // making right half equal to left half
        st.insert(getPalindrome(leftPart + 1, odd)); // next palindrome when given s is already palindrom
        st.insert(getPalindrome(leftPart - 1, odd)); // next palindrome when given s is already palindrom
        st.insert(pow(10, n - 1) - 1); // 10, 100, 1000 vala case:
        st.insert(pow(10, n) + 1); // 99, 999, 999 case:

        long long ans = 0;
        long long maxAbs = LLONG_MAX;
        long long num = stol(s);
        for(auto i: st) {
            cout << i << endl;
            if(abs(num - i) < maxAbs && abs(num - i) != 0) {
                maxAbs = abs(num - i);
                ans = i;
            }
        }

        // ** for cases like 101, 1001, they are included in 10, 100, 1000 as there near are also like them

        return to_string(ans);
    }
};