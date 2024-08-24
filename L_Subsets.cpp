class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp, int index) {
        if(index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        solve(nums, ans, temp, index + 1);
        temp.push_back(nums[index]);
        solve(nums, ans, temp, index + 1);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // using recursion:
        // vector<vector<int>> ans;
        // vector<int> temp;
        // solve(nums, ans, temp, 0);
        // return ans;



        // using bit manipulatioin:
        // vector<vector<int>> ans;
        // for(int i=0; i<(1<<nums.size()); i++) { // if size of nums is n then total 2^n subsets are possible
        //     vector<int> temp;
        //     int index = i;
        //     for(int j=nums.size()-1; j>=0; j--) {
        //         if(index & 1) temp.push_back(nums[j]);
        //         index >>= 1;
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;


        // iterative:
        vector<vector<int>> ans;
        ans.push_back({});
        for(auto i: nums) {
            int size = ans.size();
            for(int j=0; j<size; j++) {
                vector<int> temp = ans[j];
                temp.push_back(i);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};