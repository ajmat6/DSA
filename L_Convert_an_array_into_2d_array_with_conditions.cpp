class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq (n + 1, 0);

        vector<vector<int>> ans;
        for(int element: nums)
        {
            freq[element]++;
            if(freq[element] > ans.size()) ans.push_back({});
            ans[freq[element] - 1].push_back(element);
        }

        return ans;
    }
};