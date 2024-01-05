class Solution {
public:
    int solve(int startIndex, int endIndex, vector<int>& cuts, vector<vector<int>>& dp)
    {
        if(startIndex > endIndex) return 0;

        if(dp[startIndex][endIndex] != -1) return dp[startIndex][endIndex];

        int ans = INT_MAX;
        for(int i=startIndex; i<=endIndex; i++)
        {
            int leftSide = solve(startIndex, i-1, cuts, dp);
            int rightSide = solve(i+1, endIndex, cuts, dp);

            // determining current stick length by cuts array -> that why 0 and initial length of string were inserted into the string;
            ans = min(ans, cuts[endIndex+1] - cuts[startIndex-1] + leftSide + rightSide);
        }

        return dp[startIndex][endIndex] = ans;
    }

    int solve2(vector<int>& cuts)
    {
        vector<vector<int>> dp (cuts.size(), vector<int> (cuts.size(), 0));

        for(int startIndex=cuts.size()-2; startIndex>=1; startIndex--)
        {
            for(int endIndex=1; endIndex<=cuts.size()-2; endIndex++)
            {
                if(startIndex > endIndex) continue; // base case
                
                int ans = INT_MAX;
                for(int i=startIndex; i<=endIndex; i++)
                {
                    int leftSide = dp[startIndex][i-1];
                    int rightSide = dp[i+1][endIndex];

                    ans = min(ans, cuts[endIndex+1] - cuts[startIndex-1] + leftSide + rightSide);
                }

                if(ans == INT_MAX) ans = 0;
                dp[startIndex][endIndex] = ans;
            }
        }

        return dp[1][cuts.size()-2];
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n); // 0 and length of stick are inserted to get the length of string at each recursive iteration
        // vector<vector<int>> dp (cuts.size(), vector<int> (cuts.size(), -1));
        // return solve(1, cuts.size()-2, cuts, dp);

        // Tabulation:
        return solve2(cuts);
    }
};