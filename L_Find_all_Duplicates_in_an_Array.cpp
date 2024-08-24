class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            int value = abs(nums[i]);
            if(nums[value - 1] < 0) ans.push_back(value);
            else nums[value - 1] *= -1;
        }
        return ans;
    }
};