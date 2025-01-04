class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count = 0;
        for(int i=0; i<26; i++) {
            int first = -1, last = -1;
            for(int j=0; j<s.size(); j++) {
                if(s[j] - 'a' == i) {
                    if(first == -1) first = j;
                    else last = j;
                }
            }

            if(first != -1 && last != -1) {
                vector<int> freq (26);
                for(int j=first+1; j<last; j++) freq[s[j] - 'a']++;
                for(int j=0; j<26; j++) {
                    if(freq[j]) count++;
                }
            }
        }
        return count;
    }
};







class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first (26, -1);
        vector<int> last (26, -1);
        int n = s.size();
        for(int i=0; i<n; i++) {
            int charIndex = s[i] - 'a';
            if(first[charIndex] == -1) first[charIndex] = i;
            else last[charIndex] = i;
        }

        int count = 0;
        for(int i=0; i<26; i++) {
            if(first[i] != -1 && last[i] != -1) {
                vector<int> freq (26);
                for(int j=first[i]+1; j<last[i]; j++) freq[s[j] - 'a']++;
                for(int j=0; j<26; j++) {
                    if(freq[j]) count++;
                }
            }
        }
        return count;
    }
};