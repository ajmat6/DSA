class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;

        for(int i=0; i<groupSizes.size(); i++)
        {
            int groupNo = groupSizes[i];
            int No = i;

            mp[groupNo].push_back(No);

            // if the group is filled till group size:
            if(mp[groupNo].size() == groupNo)
            {
                ans.push_back(mp[groupNo]);
                mp.erase(groupNo);
            }
        }

        for(auto i: mp)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};