class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if(a.first < b.first) return true;
        else if(a.first == b.first) return a.second > b.second;
        else return false;
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto i: nums) mp[i]++;
        vector<pair<int, int>> temp;
        for(auto i: mp) temp.push_back({i.second, i.first});
        sort(temp.begin(), temp.end(), cmp);
        vector<int> ans;
        for(int i=0; i<temp.size(); i++) {
            for(int j=0; j<temp[i].first; j++) ans.push_back(temp[i].second);
        }
        return ans;
    }
};