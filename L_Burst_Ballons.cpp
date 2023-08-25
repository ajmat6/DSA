class Solution {
public:
    int recursive(vector<int>& nums, int i, int j)
    {
        // Base Case:
        if(i > j) return 0;

        int ans = INT_MIN;
        for(int index=i; index<=j; index++)
        {
            // Bursting the current index balloon, counting the coins and calling function recursively for left and right side of the index:
            int coins = nums[i-1] * nums[index] *  nums[j+1];
            
            int leftSide = recursive(nums, i, index-1);
            int rightSide = recursive(nums, index+1, j);

            int totalCoins = coins + leftSide + rightSide;

            ans = max(ans, totalCoins);
        }

        return ans;
    }

    // Memorisation:
    int Memo(vector<int>& nums, int i, int j, vector<vector<int>>& dp)
    {
        // Base Case:
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MIN;
        for(int index=i; index<=j; index++)
        {
            // Bursting the current index balloon, counting the coins and calling function recursively for left and right side of the index:
            int coins = nums[i-1] * nums[index] *  nums[j+1];
            
            int leftSide = Memo(nums, i, index-1, dp);
            int rightSide = Memo(nums, index+1, j, dp);

            int totalCoins = coins + leftSide + rightSide;

            ans = max(ans, totalCoins);
        }

        dp[i][j] = ans;

        return ans;
    }

    // Memorisation:
    int Tab(vector<int>& nums)
    {
        vector<vector<int>> dp (nums.size(), vector<int> (nums.size(), 0));

        for(int i=nums.size()-2; i>=1; i--)
        {
            for(int j=1; j<=nums.size()-2; j++)
            {
                if(i > j) continue;
                int ans = INT_MIN;
                for(int index=i; index<=j; index++)
                {
                    // Bursting the current index balloon, counting the coins and calling function recursively for left and right side of the index:
                    int coins = nums[i-1] * nums[index] *  nums[j+1];
                    
                    int leftSide = dp[i][index-1];
                    int rightSide = dp[index+1][j];

                    int totalCoins = coins + leftSide + rightSide;

                    ans = max(ans, totalCoins);
                }

                dp[i][j] = ans;
            }
        }

        return dp[1][nums.size()-2];
    }

    int maxCoins(vector<int>& nums) {
        // adding 1 on both sides for the bounding problem:
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        // return recursive(nums, 1, nums.size()-2);

        // vector<vector<int>> dp (nums.size()-1, vector<int> (nums.size()-1, -1));
        // return Memo(nums, 1, nums.size()-2, dp);

        return Tab(nums);
    }
};