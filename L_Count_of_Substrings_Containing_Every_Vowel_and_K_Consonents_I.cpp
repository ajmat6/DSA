class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            int c = 0;
            vector<int> freq (5);
            for(int j=i; j<n; j++) {
                if(word[j] == 'a') freq[0]++;
                else if(word[j] == 'e') freq[1]++;
                else if(word[j] == 'i') freq[2]++;
                else if(word[j] == 'o') freq[3]++;
                else if(word[j] == 'u') freq[4]++;
                else c++;

                bool poss = true;
                for(auto k: freq) {
                    if(k == 0) {
                        poss = false;
                        break;
                    }
                }
                
                if(poss && c == k) ans++;
                else if(c > k) break;
            }
        }
        return ans;
    }
};