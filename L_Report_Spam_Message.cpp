class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        map<string, int> mp;
        for(auto i: bannedWords) mp[i]++;

        int count = 0;
        for(auto i: message) {
            if(mp.count(i) != 0) count++;
            if(count == 2) return true;
        }
        return false;
    }
};