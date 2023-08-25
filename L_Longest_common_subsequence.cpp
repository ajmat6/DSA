class Solution {
public:
    int solve(string& s1, string& s2, int i, int j)
    {
        // Base Case:
        if(i >= s1.size() || j >= s2.size())
        {
            return 0;
        }

        // if both pointer elements are equal:
        if(s1[i] == s2[j]) return 1 + solve(s1, s2, i+1, j+1);

        // if both pointer elements are not equal:
        int ans1 = solve(s1, s2, i+1, j);
        int ans2 = solve(s1, s2, i, j+1);

        return max(ans1, ans2);
    }

    // Memorisation:
    int solve2(string& s1, string& s2, int i, int j, vector<vector<int>>& dp)
    {
        if(i >= s1.size() || j >= s2.size())
        {
            return 0;
        }

        // Check for dp:
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return 1 + solve2(s1, s2, i+1, j+1, dp);

        // if both pointer elements are not equal:
        int ans1 = solve2(s1, s2, i+1, j, dp);
        int ans2 = solve2(s1, s2, i, j+1, dp);

        dp[i][j] = max(ans1, ans2);

        return dp[i][j];
    }

    int solve3(string& s1, string& s2)
    {
        // Creating a 2d dp vector:
        vector<vector<int>> dp (s1.size()+1, vector<int> (s2.size()+1, 0));

        for(int i=s1.size()-1; i>=0; i--)
        {
            for(int j=s2.size()-1; j>=0; j--)
            {
                if(s1[i] == s2[j])
                {
                    dp[i][j] = 1 + dp[i+1][j+1];
                    continue;
                } 

                // if both pointer elements are not equal:
                int ans1 = dp[i+1][j];
                int ans2 = dp[i][j+1];

                dp[i][j] = max(ans1, ans2);
            }
        }

        return dp[0][0];
    }

    // Space Optimisation:
    int solve4(string& s1, string& s2)
    {
        // Creating 2 1dp vector:
        vector<int> curr (s2.size()+1, 0);
        vector<int> next (s2.size()+1, 0);

        for(int i=s1.size()-1; i>=0; i--)
        {
            for(int j=s2.size()-1; j>=0; j--)
            {
                if(s1[i] == s2[j])
                {
                    curr[j] = 1 + next[j+1];
                    continue;
                } 

                // if both pointer elements are not equal:
                int ans1 = next[j];
                int ans2 = curr[j+1];

                curr[j] = max(ans1, ans2);
            }
            next = curr;
        }

        return curr[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // return solve(text1, text2, 0, 0);

        // Memorisation:
        // vector<vector<int>> dp (text1.size()+1, vector<int> (text2.size()+1, -1));
        // return solve2(text1, text2, 0, 0, dp);

        // Tabulation:
        // return solve3(text1, text2);

        // Space Optimisation:
        return solve4(text1, text2);
    }
};