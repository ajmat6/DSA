class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped)
    {
        // Base case:
        if(index == nums1.size()) return 0;

        // finding prev indexes element of both arrays:
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        // if prev1 and prev2 were swapped (swap them as they actually inverseely prev1 and prev2):
        if(swapped) swap(prev1, prev2);

        int ans = INT_MAX;

        // Not swapping case:
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index+1, false);

        // Swapping case:
        if(nums1[index] > prev2 && nums2[index] > prev1)
        {
            ans = min(ans, 1 + solve(nums1, nums2, index+1, true));
        }

        return ans;
    }

    // Memorisation:
    int solve2(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>>& dp)
    {
        // Base case:
        if(index == nums1.size()) return 0;

        // finding prev indexes element of both arrays:
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        // if prev1 and prev2 were swapped (swap them as they actually inverseely prev1 and prev2):
        if(swapped) swap(prev1, prev2);

        // check for dp:
        if(dp[index][swapped] != -1) return dp[index][swapped];

        int ans = INT_MAX;

        // Not swapping case:
        if(nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve2(nums1, nums2, index+1, false, dp);

        // Swapping case:
        if(nums1[index] > prev2 && nums2[index] > prev1)
        {
            ans = min(ans, 1 + solve2(nums1, nums2, index+1, true, dp));
        }

        // storing ans in dp:
        dp[index][swapped] = ans;

        return ans;
    }

    // Tabulation:
    int solve3(vector<int>& nums1, vector<int>& nums2)
    {
        vector<vector<int>> dp (nums1.size()+1, vector<int> (2, 0));

        for(int index=nums1.size()-1; index>=1; index--)
        {
            for(int swapped=1; swapped>=0; swapped--)
            {
                // finding prev indexes element of both arrays:
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // if prev1 and prev2 were swapped (swap them as they actually inverseely prev1 and prev2):
                if(swapped) swap(prev1, prev2);

                int ans = INT_MAX;

                // Not swapping case:
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index+1][0];

                // Swapping case:
                if(nums1[index] > prev2 && nums2[index] > prev1)
                {
                    ans = min(ans, 1 + dp[index+1][1]);
                }

                // storing ans in dp:
                dp[index][swapped] = ans;
            }
        }

        return dp[1][0];
    }

    // Space Optimisation:
    int solve4(vector<int>& nums1, vector<int>& nums2)
    {
        // Defining two integer for [index+1][0] and [index][1]:
        int notswap = 0;
        int swapp = 0;
        int currswap;
        int currnoSwap;

        for(int index=nums1.size()-1; index>=1; index--)
        {
            for(int swapped=1; swapped>=0; swapped--)
            {
                // finding prev indexes element of both arrays:
                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // if prev1 and prev2 were swapped (swap them as they actually inverseely prev1 and prev2):
                if(swapped) swap(prev1, prev2);

                int ans = INT_MAX;

                // Not swapping case:
                if(nums1[index] > prev1 && nums2[index] > prev2)
                    ans = notswap;

                // Swapping case:
                if(nums1[index] > prev2 && nums2[index] > prev1)
                {
                    ans = min(ans, 1 + swapp);
                }

                // storing ans:
                if(swapped) currswap = ans;
                else currnoSwap = ans;
            }
            swapp = currswap;
            notswap = currnoSwap;
        }

        return min(swapp, notswap);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // inserting -1 int the beginning of both the arrays:
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        bool swapped = false;
        
        // return solve(nums1, nums2, 1, swapped);

        // Memorisation:
        // vector<vector<int>> dp (nums1.size()+1, vector<int> (2, -1));
        // return solve2(nums1, nums2, 1, swapped, dp);

        // Tabulation:
        // return solve3(nums1, nums2);

        // Space Optimisation:
        return solve4(nums1, nums2);
    }
};