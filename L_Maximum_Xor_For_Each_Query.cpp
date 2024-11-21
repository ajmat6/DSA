class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int n = nums.size(); int currXor = 0;
        int maxValue = pow(2, maximumBit) - 1;
        for(int i=0; i<n; i++) {
            currXor ^= nums[i];
            ans.push_back(maxValue ^ currXor);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};