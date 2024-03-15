class Solution {
public:
    map<pair<int, long long int>, int> dp;
    int solve(vector<int>& nums, int prev, int curr, long long int diff)
    {
        if(curr == nums.size()) return 0;

        // dp check:
        if(dp[{prev, diff}]) return dp[{prev, diff}];

        int ans = 0;
        for(int i=curr; i<nums.size(); i++)
        {
            long long int dif = (long long int) nums[i] - nums[prev];
            if(dif == diff) ans += 1 + solve(nums, i, i + 1, diff);
        }

        return dp[{prev, diff}] = ans;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        // recursive +  memorisation:
        int n = nums.size();
        if(n < 3) return 0;
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                long long int diff = (long long int) nums[j] - nums[i];
                ans += solve(nums, j, j + 1, diff);
            }
        }

        return ans;

        // iterative using LIS concept:
        // int n = nums.size();
        // vector<unordered_map<long long int, int>> dp (n);

        // int ans = 0;
        // for(int i=1; i<n; i++)
        // {
        //     for(int j=0; j<i; j++)
        //     {
        //         long long int diff = (long long int) nums[i] - nums[j];
        //         dp[i][diff] += 1 + dp[j][diff];
        //         ans += dp[j][diff];
        //     }
        // }

        // return ans;
    }
};