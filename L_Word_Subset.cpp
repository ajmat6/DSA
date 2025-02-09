class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int freq2[26] = {0};
        for(int i=0; i<words2.size(); i++) {
            int temp[26] = {0};
            for(auto &j: words2[i]) temp[j - 'a']++;
            for(int j=0; j<26; j++) freq2[j] = max(freq2[j], temp[j]);
        }

        vector<string> ans;
        for(int i=0; i<words1.size(); i++) {
            int temp[26] = {0};
            for(auto &j: words1[i]) temp[j - 'a']++;
            int poss = 1;
            for(int j=0; j<26; j++) {
                if(temp[j] < freq2[j]) {
                    poss = false;
                    break;
                }
            }
            if(poss) ans.push_back(words1[i]);
        }
        return ans;
    }
};