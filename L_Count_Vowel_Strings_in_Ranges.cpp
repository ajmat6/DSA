class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> mp (n, 0);
        int prev = 0;
        for(int i=0; i<n; i++) {
            if(isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1])) mp[i] = 1 + prev;
            else mp[i] = prev;
            prev = mp[i];
        }

        vector<int> ans;
        for(int i=0; i<queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if(a == 0) ans.push_back(mp[b]);
            else ans.push_back(mp[b] - mp[a - 1]);
        }
        return ans;
    }
};