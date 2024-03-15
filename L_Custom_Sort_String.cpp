class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for(auto i: s) mp[i]++;

        string ans = "";
        for(auto i: order) {
            if(mp.find(i) != mp.end()) {
                ans.append(mp[i], i);
                mp[i] = 0;
            }
        }

        for(auto i: mp) {
            if(i.second > 0) {
                ans.append(i.second, i.first);
            } 
        }

        return ans;
    }
};