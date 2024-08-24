class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> freq (words.size(), vector<int> (26, 0));
        for(int i=0; i<words.size(); i++) {
            for(int j=0; j<words[i].size(); j++) {
                freq[i][words[i][j] - 'a']++;
            }
        }

        vector<string> ans;
        for(int i=0; i<words[0].size(); i++) {
            char ch = words[0][i];

            // check if this character is there in every word:
            bool poss = true;
            for(int j=1; j<words.size(); j++) {
                if(freq[j][ch - 'a'] == 0) {
                    poss = false;
                    break;
                }
            }

            // if it is, then add it into answer and reduce its frequency in every freq vector:
            if(poss) {
                string a = "";
                a += ch;
                ans.push_back(a);
                for(int j=0; j<words.size(); j++) {
                    freq[j][ch - 'a']--;
                }
            }
        }
        return ans;
    }
};