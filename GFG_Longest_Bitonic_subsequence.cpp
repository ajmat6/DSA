class Solution{
	public:
	int solve(vector<int>& nums, int curr, int prev,  vector<vector<int>>& dp)
	{
	    if(curr == nums.size()) return 0;
	    
	    if(dp[curr][prev + 1] != -1) return dp[curr][prev + 1];
	    
	    int include = 0;
	    if(prev == -1 || nums[curr] > nums[prev])
	    {
	        include = 1 + solve(nums, curr + 1, curr, dp);
	    }
	    
	    int exclude = 0 + solve(nums, curr + 1, prev, dp);
	    
	    int ans = max(include, exclude);
	    return dp[curr][prev + 1] = ans;
	}
	
	int LongestBitonicSequence(vector<int>nums)
	{
	    vector<vector<int>> dpIn (nums.size(), vector<int> (nums.size()+1, -1));
	    vector<vector<int>> dpDe (nums.size(), vector<int> (nums.size()+1, -1));
	    solve(nums, 0, -1, dpIn);
	    reverse(nums.begin(), nums.end());
	    solve(nums, 0, -1, dpDe);
	    
	    int ans = 0;
	    for(int i=0; i<dpIn.size(); i++)
	    {
	        for(int j=0; j<dpIn[0].size(); j++)
	        {
	            if(dpIn[i][j] + dpDe[i][j] > ans) ans = dpIn[i][j] + dpDe[i][j];
	        }
	    }
	    
	    return ans - 1;
	    
	   // vector<int> dpIn (nums.size(), 1);
	   // vector<int> dpDe (nums.size(), 1);
	    
	   // // for finding LIS from starting:
	   // for(int i=0; i<nums.size(); i++)
	   // {
	   //     for(int prev=0; prev<i; prev++)
	   //     {
	   //         if(nums[i] > nums[prev] && dpIn[prev] + 1 > dpIn[i])
	   //         {
	   //             dpIn[i] = 1 + dpIn[prev];
	   //         }
	   //     }
	   // }
	    
	   // // for finding LIS from the end of the nums for decreasing part:
	   // for(int i=nums.size()-2; i>=0; i--)
	   // {
	   //     for(int prev=nums.size()-1; prev>i; prev--)
	   //     {
	   //         if(nums[i] > nums[prev] && dpDe[prev] + 1 > dpDe[i])
	   //         {
	   //             dpDe[i] = 1 + dpDe[prev];
	   //         }
	   //     }
	   // }
	    
	   // int ans = 0;
	   // for(int i=0; i<dpIn.size(); i++)
	   // {
	   //     if(dpIn[i] + dpDe[i] > ans)
	   //     {
	   //         ans = dpIn[i] + dpDe[i];
	   //     }
	   // }
	    
	   // return ans - 1;
	}
};