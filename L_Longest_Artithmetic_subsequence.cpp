class Solution {
public:
    int solve(vector<int>&nums, int index, int commDiff)
    {
        if(index <= 0) return 0;

        int ans = 0;
        for(int i=index-1; i>=0; i--)
        {
            int include;
            if(nums[index]-nums[i] == commDiff)
            {
                ans = max(ans, 1 + solve(nums, i, commDiff));
            }
        }

        return ans;
    }

    // Memorisation:
    int solve2(vector<int>&nums, int index, int commDiff, unordered_map<int, int> dp[])
    {
        if(index <= 0) return 0;

        // checking for dp map:
        if(dp[index].count(commDiff) > 0) return dp[index][commDiff];

        int ans = 0;
        for(int i=index-1; i>=0; i--)
        {
            int include;
            if(nums[index]-nums[i] == commDiff)
            {
                ans = max(ans, 1 + solve2(nums, i, commDiff, dp));
            }
        }

        dp[index][commDiff] = ans;

        return ans;
    }

    int solve3(vector<int>&nums, int index, int commDiff)
    {
        if(index <= 0) return 0;

        int ans = 0;
        for(int i=index-1; i>=0; i--)
        {
            int include;
            if(nums[index]-nums[i] == commDiff)
            {
                ans = max(ans, 1 + solve(nums, i, commDiff));
            }
        }

        return ans;
    }

    int longestArithSeqLength(vector<int>& nums) {
        // if size of input vector is less than 2:
        // if(nums.size() <= 2) return nums.size();

        // int ans = 0;
        
        // for(int i=0; i<nums.size()-1; i++)
        // {
        //     for(int j=i+1; j<nums.size(); j++)
        //     {
        //         // finding lesser index element in nums with common diff of nums[i]-nums[j] and then adding 2 into it (current indexes):
        //         ans = max(ans, 2 + solve(nums, i, nums[j]-nums[i]));
        //     }
        // }

        // Memorisation:
        // if(nums.size() <= 2) return nums.size();

        // int ans = 0;
        // Creating array of unordered map
        // unordered_map<int, int> dp [nums.size()+1];
        // for(int i=0; i<nums.size()-1; i++)
        // {
        //     for(int j=i+1; j<nums.size(); j++)
        //     {
        //         // finding lesser index element in nums with common diff of nums[i]-nums[j] and then adding 2 into it (current indexes):
        //         ans = max(ans, 2 + solve2(nums, i, nums[j]-nums[i], dp));
        //     }
        // }

        // Tabulation:
        if(nums.size() <= 2) return nums.size();
        
        int ans = 0;

        // Creating array of unordered map for dp:
        unordered_map<int, int> dp [nums.size()+1];

        for(int i=1; i<nums.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                int commDiff = nums[i] - nums[j];
                int count = 1;

                // check for dp:
                if(dp[j].count(commDiff) > 0)
                {
                    count = dp[j][commDiff];
                }

                // updating curr index max Elements with commDiff (storing in dp):
                dp[i][commDiff] = 1 + count;

                // updating max elements with same commDiff:
                ans = max(ans, dp[i][commDiff]);
            }
        }

        return ans;
    }
};