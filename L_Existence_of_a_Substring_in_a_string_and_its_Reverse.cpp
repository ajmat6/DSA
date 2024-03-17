class Solution {
public:
    bool isSubstringPresent(string s) {
        map<string, int> mp;
        for(int i=0; i<s.size()-1; i++) {
            string temp = s.substr(i, 2);
            mp[temp]++;
        }
        
        reverse(s.begin(), s.end());
        for(int i=0; i<s.size()-1; i++) {
            string temp = s.substr(i, 2);
            if(mp.find(temp) != mp.end()) return true;
        }
        
        return false;
    }
};