class Solution {
public:
    int numberOfSubstrings(string s, int x) {
        int count = 0;
        int n = s.size();
        for(int i=0; i<n; i++) {
            vector<int> freq (26, 0);
            for(int j=i; j<n; j++) {
                freq[s[j] - 'a']++;
                for(int k=0; k<26; k++) {
                    if(freq[k] >= x) {
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};