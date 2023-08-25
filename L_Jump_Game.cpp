class Solution {
public:
    bool solve(vector<int>& nums, int index)
    {
        // Base Case:
        if(index == nums.size()-1) return true;
        if(index >= nums.size()) return false;

        // checking each possible jump at an index:
        bool ans = false;
        for(int i=1; i<=nums[index]; i++)
        {
            bool result = solve(nums, index+i);
            // update ans to true if there is any possible way to reach final index:
            if(result) ans = result;
        }

        return ans;
    }

    bool solveMem(vector<int>& nums, int index, vector<int>& dp)
    {
        if(index == nums.size()-1) return true;
        if(index >= nums.size()) return false;


        // check for dp:
        if(dp[index] != -1) return dp[index];

        for(int i=1; i<=nums[index]; i++)
        {
            bool result = solveMem(nums, index+i, dp);
            if(result)
            {
                dp[index] = true;
                return dp[index];
            }
        }

        // storing in dp:
        dp[index] = false;

        return dp[index];
    }

    bool solveTab(vector<int>& nums)
    {
        vector<bool> dp (nums.size(), false);

        dp[nums.size()-1] = true;

        for(int index=nums.size()-2; index>=0; index--)
        {
            for(int i=1; i<=nums[index]; i++)
            {
                // if for valid index in dp:
                if(index+i < dp.size())
                {
                    bool result = dp[index+i];
                    if(result)
                    {
                        dp[index] = true;
                        break; // break loop if true is found
                    }
                }
            }
        }

        return dp[0];
    }

    bool canJump(vector<int>& nums) {
        // return solve(nums, 0);

        // Memorisation:
        // vector<int> dp (nums.size(), -1);
        // return solveMem(nums, 0, dp);

        // Tabulaton:
        // return solveTab(nums);

        // Iterative:
        int maxDistance = 0;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(i > maxDistance) return false;
            maxDistance = max(maxDistance, i + nums[i]);
        }

        if(maxDistance >= nums.size()-1) return true;
        else return false;
    }
};