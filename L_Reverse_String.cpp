class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0; i<s.size() / 2; i++) {
            char a = s[i];
            char b = s[s.size() - 1 - i];
            s[i] = b;
            s[s.size() - 1 - i] = a;
        }
    }
};