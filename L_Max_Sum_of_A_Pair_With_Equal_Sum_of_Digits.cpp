class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        vector<int> sums (82,-1); // max possible no is 999999999 whose sum is 81
        
        for(int i=0; i<nums.size(); i++) {
            int element = nums[i], sum = 0;
            while(element) {
                sum += element % 10;
                element /= 10;
            }
            if(sums[sum] != -1) ans = max(ans, sums[sum] + nums[i]);
            sums[sum] = max(sums[sum], nums[i]);
        }

        return ans;
    }
};