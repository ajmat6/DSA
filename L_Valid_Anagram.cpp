class Solution {
public:
    bool isAnagram(string s, string t) {
        // using sort: nlogn + mlogm time and const space:
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;

        // using freq count: n + 26 time and 26 space:
        vector<int> freq(26);
        if(s.size() != t.size()) return false;
        for(int i=0; i<s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for(auto i: freq) {
            if(i != 0) return false;
        }
        return true;
    }
};