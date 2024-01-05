class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> left (nums.size(), -1);
        vector<int> right (nums.size(), -1);
        int mini = nums[0];

        // finding left min for each index keeping in mind that left min should be smaller than the current index value and similarly below right min:
        for(int i=1; i<nums.size()-1; i++)
        {
            if(mini < nums[i])
            {
                left[i] = mini;
            }

            mini = min(mini, nums[i]);
        }

        mini = nums[nums.size()-1]; // reseting mini for right min
        for(int i=nums.size()-2; i>0; i--)
        {
            if(mini < nums[i])
            {
                right[i] = mini;
            }

            mini = min(mini, nums[i]);
        }

        int ans = INT_MAX;
        for(int i=1; i<nums.size()-1; i++)
        {
            // if there is either no min element on left or no min element on right:
            if(left[i] != -1 && right[i] != -1)
            {
                ans = min(ans, left[i] + nums[i] + right[i]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};