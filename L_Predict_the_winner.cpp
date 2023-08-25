class Solution {
public:
    int solve(vector<int>& nums, int whichNo, int i, int j)
    {
        // Base Case:
        if(i > j) return 0;

        int ans = 0;
        // if it is player no 1 turn, call for both possible cases of selecting ith and jth index and inlcude score in ans:
        if(whichNo == 1)
        {
            // if ith and jth index no is selected:
            int ith = nums[i] + solve(nums, 2, i+1, j);
            int jth = nums[j] + solve(nums, 2, i, j-1);

            ans = max(ith, jth);
        }

        // if it is player no 2 turn, then we dont have to include current index score in ans:
        if(whichNo == 2)
        {
            // if ith and jth index no is selected:
            int ith = 0 + solve(nums, 1, i+1, j);
            int jth = 0 + solve(nums, 1, i, j-1);

            ans = min(ith, jth); // we want to check if 1st player can win in any case, so taking min of scores possible for player 2
        }

        return ans;
    }

    int solve2(vector<int>& nums, int whichNo, int i, int j, vector<vector<int>>& dp)
    {
        // Base Case:
        if(i > j) return 0;

        // check for dp:
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        // if it is player no 1 turn, call for both possible cases of selecting ith and jth index and inlcude score in ans:
        if(whichNo == 1)
        {
            // if ith and jth index no is selected:
            int ith = nums[i] + solve2(nums, 2, i+1, j, dp);
            int jth = nums[j] + solve2(nums, 2, i, j-1, dp);

            ans = max(ith, jth);
        }

        // if it is player no 2 turn, then we dont have to include current index score in ans:
        if(whichNo == 2)
        {
            // if ith and jth index no is selected:
            int ith = 0 + solve2(nums, 1, i+1, j, dp);
            int jth = 0 + solve2(nums, 1, i, j-1, dp);

            ans = min(ith, jth); // we want to check if 1st player can win in any case, so taking min of scores possible for player 2
        }

        return dp[i][j] = ans;
    }

    // Tabulation:
    int solve3(vector<int>& nums)
    {
        vector<vector<int>> dp (nums.size(), vector<int> (nums.size(), 0));

        for(int i=0; i<nums.size(); i++) dp[i][i] = nums[i];

        // for(int i)

        int whichNo = 1;
        int i = 0;
        int j = nums.size()-1;
        while(i <= j)
        {
            int ans = 0;
            // if it is player no 1 turn, call for both possible cases of selecting ith and jth index and inlcude score in ans:
            if(whichNo == 1)
            {
                // if ith and jth index no is selected:
                int ith = nums[i] + dp[i+1][j];
                int jth = nums[j] + dp[i][j-1];

                ans = max(ith, jth);
            }

            // if it is player no 2 turn, then we dont have to include current index score in ans:
            if(whichNo == 2)
            {
                // if ith and jth index no is selected:
                int ith = 0 + dp[i+1][j];
                int jth = 0 + dp[i][j-1];

                ans = min(ith, jth); // we want to check if 1st player can win in any case, so taking min of scores possible for player 2
            }

            dp[i][j] = ans;
        }


        return dp[0][nums.size()-1];
    }

    bool PredictTheWinner(vector<int>& nums) {
        // calculating total score:
        int totalScore = 0;
        for(auto i: nums)
        {
            totalScore += i;
        }

        // calculating min score req for 1st player to win:
        int finalScore;
        if(totalScore % 2 == 0) finalScore = totalScore / 2;
        else finalScore = totalScore / 2 + 1;

        // recursion:
        // int score = solve(nums, 1, 0, nums.size()-1);
        // if(score >= finalScore) return true;
        // else return false;

        // Memorisation:
        vector<vector<int>> dp (nums.size(), vector<int> (nums.size(), -1));
        int score = solve2(nums, 1, 0, nums.size()-1, dp);
        if(score >= finalScore) return true;
        else return false;
    }
};