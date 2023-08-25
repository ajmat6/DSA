class Solution {
public:
    bool checkSum(vector<int>& nums, int low, int high, int m)
    {
        int sum = 0;
        for(int i=low; i<=high; i++)
        {
            sum +=  nums[i];
        }
        
        if(sum >= m) return true;
        else return false;
    }
    
    bool check(vector<int>& nums, int m, int low, int high, int sum)
    {
        if(high - low <= 1) return true;
        
        bool leftSideSplit = false;
        bool rightSideSplit = false;
        
        int rightSide = sum - nums[high];
        
        if(rightSide >= m)
        {
            rightSideSplit = check(nums, m, low, high-1, sum-nums[high]);
        }
        int leftSide = sum - nums[low];
        if(leftSide >= m)
        {
            leftSideSplit = check(nums, m, low+1, high, sum-nums[low]);
        }
        
        if(leftSideSplit || rightSideSplit) return true;
        else return false;
    }
    
    bool check2(vector<int>& nums, int m, int low, int high, int sum, vector<vector<int>>& dp)
    {
        if(high - low <= 1) return true;
        
        if(dp[low][high] != -1) return dp[low][high];
        
        bool leftSideSplit = false;
        bool rightSideSplit = false;
        
        int rightSide = sum - nums[high];
        if(rightSide >= m)
        {
            rightSideSplit = check2(nums, m, low, high-1, sum-nums[high], dp);
        }
        
        int leftSide = sum - nums[low];
        if(leftSide >= m)
        {
            leftSideSplit = check2(nums, m, low+1, high, sum-nums[low], dp);
        }
        
        if(leftSideSplit || rightSideSplit)
        {
            dp[low][high] = 1;
            return true;
        }
        else
        {
            dp[low][high] = 0;
            return false;
        }
        return false;
    }
    
    bool canSplitArray(vector<int>& nums, int m) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
        }
        
        // return check(nums, m, 0, nums.size()-1, sum);
        
        // Memorisation:
        vector<vector<int>> dp (nums.size(), vector<int> (nums.size(), -1));
        return check2(nums, m, 0, nums.size()-1, sum, dp);
    }
};