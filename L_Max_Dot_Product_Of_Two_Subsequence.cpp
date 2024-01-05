class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int x, int y, vector<vector<int>>& dp)
    {
        // if(x == 0 && y == nums2.size()) return INT_MIN;
        if(x == nums1.size() || y == nums2.size()) return 0;

        if(dp[x][y] != -1) return dp[x][y];

        int ans = INT_MIN;
        int take = nums1[x] * nums2[y] + solve(nums1, nums2, x + 1, y + 1, dp); // taking present index elements
        int notTake1 = 0 + solve(nums1, nums2, x + 1, y, dp); // not taking current elements and increaing x index only
        int notTake2 = 0 + solve(nums1, nums2, x, y + 1, dp); // increasing y index only
        ans = max(ans, max(take, max(notTake1, notTake2)));

        return dp[x][y] = ans;
    }

    int solve2(vector<int>& nums1, vector<int>& nums2)
    {
        vector<vector<int>> dp (nums1.size() + 1, vector<int> (nums2.size() + 1, 0));

        for(int x=nums1.size()-1; x>=0; x--)
        {
            for(int y=nums2.size()-1; y>=0; y--)
            {
                int ans = INT_MIN;
                int take = nums1[x] * nums2[y] + dp[x+1][y+1]; // taking present index elements
                int notTake1 = 0 + dp[x+1][y]; // not taking current elements and increaing x index only
                int notTake2 = 0 + dp[x][y+1]; // increasing y index only
                ans = max(ans, max(take, max(notTake1, notTake2)));

                dp[x][y] = ans;
            }
        }

        return dp[0][0];
    }

    int solve3(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> next (nums1.size(), 0);
        vector<int> curr (nums1.size(), 0);

        for(int x=nums1.size()-1; x>=0; x--)
        {
            for(int y=nums2.size()-1; y>=0; y--)
            {
                int ans = INT_MIN;
                int take = nums1[x] * nums2[y] + next[y+1]; // taking present index elements
                int notTake1 = 0 + next[y]; // not taking current elements and increaing x index only
                int notTake2 = 0 + curr[y+1]; // increasing y index only
                ans = max(ans, max(take, max(notTake1, notTake2)));

                curr[y] = ans;
            }
            next = curr;
        }

        return curr[0];
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // there is an edge case when the max product is negative:
        // max product will be negative when max no in one is negative and min no in second is positive, then even after trying all the combinations, you will get a negative dot product:
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for(auto i: nums1)
        {
            max1 = max(max1, i);
            min1 = min(min1, i);
        }

        for(auto i: nums2)
        {
            max2 = max(max2, i);
            min2 = min(min2, i);
        }

        if(max1 < 0 && min2 > 0) return max1 * min2;
        else if(max2 < 0 && min1 > 0) return max2 * min1;

        // vector<vector<int>> dp (nums1.size(), vector<int> (nums2.size(), -1));
        // return solve(nums1, nums2, 0, 0, dp);

        // Tabulation:
        // return solve2(nums1, nums2);
        return solve2(nums1, nums2);
    }
};