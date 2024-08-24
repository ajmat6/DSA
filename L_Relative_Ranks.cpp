class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sc = score;
        sort(sc.begin(), sc.end(), greater<int> ());
        unordered_map<int, string> mp;
        for(int i=0; i<sc.size(); i++) {
            if(i == 0) mp[sc[i]] = "Gold Medal";
            else if(i == 1) mp[sc[i]] = "Silver Medal";
            else if(i == 2) mp[sc[i]] = "Bronze Medal";
            else mp[sc[i]] = to_string(i + 1);
        }

        vector<string> ans;
        for(auto i: score) ans.push_back(mp[i]);
        return ans;
    }
};