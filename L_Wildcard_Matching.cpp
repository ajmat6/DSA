class Solution {
public:
    // Recursion: Gives TLE
    int solve(string& s, string& p, int i, int j)
    {
        // condtion for pattern string not end:
        if(i < 0 && j >= 0)
        {
            for(int k=0; k<=j; k++)
            {
                if(p[k] != '*') return false;
            }

            return true;
        }

        // condition for pattern string end:
        if(j < 0 && i >= 0) return false;

        // condtion for both the strings end:
        if(i < 0 && j < 0) return true;

        // Matching conditions:
        if(s[i] == p[j]) return solve(s, p, i-1, j-1);
        if(p[j] == '?') return solve(s, p, i-1, j-1);

        else if(p[j] == '*')
        {
            // Replacing start with empty string:
            int ans1 = solve(s, p, i, j-1);

            // Replacing star with any character and again star:
            int ans2 = solve(s, p, i-1, j);

            bool ans = ans1 || ans2;
            return ans;
        }

        // Not matching condition:
        else return false;
    }

    // Memorisation:
    int solve2(string& s, string& p, int i, int j, vector<vector<int>>& dp)
    {
        // condtion for pattern string not end:
        if(i < 0 && j >= 0)
        {
            for(int k=0; k<=j; k++)
            {
                if(p[k] != '*') return false;
            }

            return true;
        }

        // condition for pattern string end:
        if(j < 0 && i >= 0) return false;

        // condtion for both the strings end:
        if(i < 0 && j < 0) return true;

        // check for dp:
        if(dp[i][j] != -1) return dp[i][j];

        // Matching conditions:
        if(s[i] == p[j]) return solve2(s, p, i-1, j-1, dp);
        if(p[j] == '?') return solve2(s, p, i-1, j-1, dp);

        else if(p[j] == '*')
        {
            // Replacing start with empty string:
            int ans1 = solve2(s, p, i, j-1, dp);

            // Replacing star with any character and again star:
            int ans2 = solve2(s, p, i-1, j, dp);

            bool ans = ans1 || ans2;
            
            // storing in dp:
            dp[i][j] = ans;
            return ans;
        }

        // Not matching condition:
        else return false;
    }

    // Tabulation:
    int solve3(string& s, string& p)
    {
        // 2D dp vector:
        vector<vector<int>> dp (s.size()+1, vector<int> (p.size()+1, 0));

        // condtion for both the strings end:
        dp[0][0] = true;

        // Handling condition for pattern string not end:
        for(int j=1; j<=p.size(); j++)
        {
            bool flag = true;
            for(int k=1; k<=j; k++)
            {
                if(p[k-1] != '*')
                {
                    flag = false;
                    break;
                }
            }

            dp[0][j] = flag;
        }

        // Handling rest of the cases:
        for(int i=1; i<=s.size(); i++)
        {
            for(int j=1; j<=p.size(); j++)
            {
                // Matching conditions:
                if(s[i-1] == p[j-1]) dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '?') dp[i][j] = dp[i-1][j-1];

                else if(p[j-1] == '*')
                {
                    // Replacing star with empty string:
                    int ans1 = dp[i][j-1];

                    // Replacing star with any character and again star:
                    int ans2 = dp[i-1][j];

                    bool ans = ans1 || ans2;
                    dp[i][j] = ans;
                }

                // Not matching condition:
                else dp[i][j] = false;
            }
        }

        return dp[s.size()][p.size()];
    }

    // Space Optimisation:
    int solve4(string& s, string& p)
    {
        // 1D dp vectors:
        vector<int> prev(p.size()+1, 0);
        vector<int> curr(p.size()+1, 0);

        // condtion for both the strings end:
        prev[0] = true;

        // Handling condition for pattern string not end:
        for(int j=1; j<=p.size(); j++)
        {
            bool flag = true;
            for(int k=1; k<=j; k++)
            {
                if(p[k-1] != '*')
                {
                    flag = false;
                    break;
                }
            }

            prev[j] = flag;
        }

        // Handling rest of the cases:
        for(int i=1; i<=s.size(); i++)
        {
            for(int j=1; j<=p.size(); j++)
            {
                // Matching conditions:
                if(s[i-1] == p[j-1]) curr[j] = prev[j-1];
                else if(p[j-1] == '?') curr[j] = prev[j-1];

                else if(p[j-1] == '*')
                {
                    // Replacing star with empty string:
                    int ans1 = curr[j-1];

                    // Replacing star with any character and again star:
                    int ans2 = prev[j];

                    bool ans = ans1 || ans2;
                    curr[j] = ans;
                }

                // Not matching condition:
                else curr[j] = false;
            }

            prev = curr;
        }

        return prev[p.size()];
    }

    bool isMatch(string s, string p) {
        // return solve(s, p, s.size()-1, p.size()-1);

        // Memorisation:
        // vector<vector<int>> dp (s.size()+1, vector<int> (p.size()+1, -1));
        // return solve2(s, p, s.size()-1, p.size()-1, dp);

        // Tabulation:
        // return solve3(s, p);

        // Space optimisation:
        return solve4(s, p);
    }
};