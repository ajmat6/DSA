class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k > n) return false;

        int freq[26] = {0}; 
        for(auto &i: s) freq[i - 'a']++;

        int count = 0;
        for(int i=0; i<26; i++) count += freq[i] % 2;
        if(count <= k) return true;
        return false;
    }
};