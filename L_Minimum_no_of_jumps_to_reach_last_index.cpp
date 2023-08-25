class Solution {
public:
    int solve(vector<int>& nums, int target, int index, vector<int>& dp)
    {
        if(index == nums.size()-1) return 0;
        
        if(dp[index] != -2) return dp[index];
        
        int ans = INT_MIN;
        int flag = 0;
        for(int i=index+1; i<nums.size(); i++)
        {
            if(abs(nums[i] - nums[index]) <= target)
            {
                flag = 1;
                int jump = 1;
                int recursive = solve(nums, target, i, dp);
                if(recursive == -1) flag = 0;
                else 
                {
                    ans = max(ans, jump+recursive);
                }
                
            }
        }
        
        
        if(flag == 0)
        {
            if(ans != INT_MIN) 
            {
                dp[index] = ans;
                return ans;
            }
            else return dp[index] = -1;
        }
        
        dp[index] = ans;
        return ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp (nums.size(), -2);
        return solve(nums, target, 0, dp);
    }
};