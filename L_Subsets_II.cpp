class Solution {
public:
    void solve(vector<int>& nums, vector<int> temp, vector<vector<int>>& ans, int index, set<vector<int>>& st)
    {
        // base case:
        if(index == nums.size()) return;

        for(int i=index; i<nums.size(); i++)
        {
            temp.push_back(nums[i]);

            // as any form of a subarray in any order cant be repeated, sorting it:
            // you cant sort original temp vector as it will create at backtracking:
            // commented becoz I sorted original array nums instead:
            // vector<int> newSorted = temp;
            // sort(newSorted.begin(), newSorted.end());

            // checking for duplicacy:
            if(st.find(temp) == st.end())
            {
              ans.push_back(temp);
                st.insert(temp);
            }

            solve(nums, temp, ans, i + 1, st);
            temp.pop_back(); // backtrack
        }

        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // vector<vector<int>> ans; // O(2^n)
        // set<vector<int>> st; // same SC
        // ans.push_back({});
        // solve(nums, {}, ans, 0, st);
        // return ans;

        // using bit maipulation:
        sort(nums.begin(), nums.end()); // to escape from duplicacy
        int total = 1 << nums.size(); // no of possible subarrays
        set<vector<int>> st;

        for(int i=0; i<total; i++)
        {
            vector<int> temp;
            for(int j=0; j<nums.size(); j++)
            {
                if((i & (1 << j)) != 0) temp.push_back(nums[j]);
            }

            st.insert(temp);
        }

        vector<vector<int>> ans = {st.begin(), st.end()};
        return ans;
    }
};