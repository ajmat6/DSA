class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;

        // setting all nos frquencies as zero:
        for(int i=1; i<=nums.size(); i++)
        {
            mp[i] = 0;
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(mp[nums[i]] == 1) ans.push_back(nums[i]);
            else mp[nums[i]]++;
        }

        for(auto i: mp)
        {
            if(i.second == 0) ans.push_back(i.first);
        }

        return ans;
    }
};