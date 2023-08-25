class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        set<int> st; // to track unique element at the curr index position
        for(int i=index; i<nums.size(); i++)
        {
            // if the curr index element is unique, it can give unique  permutation:
            if(st.find(nums[i]) == st.end())
            {
                st.insert(nums[i]);
                swap(nums[i], nums[index]);
                solve(nums, ans, index + 1);
                swap(nums[i], nums[index]);
            }
        }

        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};