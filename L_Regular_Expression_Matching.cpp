class Solution {
public:
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp)
    {
        if(i == s.size() && j == p.size()) return true; // both ended
        if(j == p.size()) return false; // pattern ended

        if(dp[i][j] != -1) return dp[i][j];

        // if curr pattern char is '.' or matches exactly with input string char:
        bool match = i < s.size() && s[i] == p[j] || i < s.size() && p[j] == '.';

        bool take = false;
        bool notTake = false;

        // if curr next char is '*':
        if(j < p.size() - 1 && p[j+1] == '*')
        {
            // not using power of *:
            notTake = solve(s, p, i, j+2, dp);

            // we will take power of * only when match is true:
            if(match) take = solve(s, p, i+1, j, dp);

            bool ans = take || notTake;
            return dp[i][j] = ans;
        }

        // if next pattern char is not *:
        else
        {
            if(match) return dp[i][j] = solve(s, p, i+1, j+1, dp);
            else return dp[i][j] = false;
        }
        return true; // not reachable
    }

    bool solve2(string& s, string& p)
    {
        vector<vector<int>> dp (s.size()+1, vector<int> (p.size()+1, -1));

        dp[s.size()][p.size()] = 1;
        for(int i=0; i<s.size(); i++)
        {
            dp[i][p.size()] = 0;
        }

        for(int i=s.size(); i>=0; i--)
        {
            for(int j=p.size(); j>=0; j--)
            {
                if(i == s.size() && j == p.size()) continue;
                
                // if curr pattern char is '.' or matches exactly with input string char:
                bool match = i < s.size() && s[i] == p[j] || i < s.size() && p[j] == '.';

                bool take = false;
                bool notTake = false;

                // if curr next char is '*':
                if(j < p.size() - 1 && p[j+1] == '*')
                {
                    // not using power of *:
                    notTake = dp[i][j+2];

                    // we will take power of * only when match is true:
                    if(match) take = dp[i+1][j];

                    bool ans = take || notTake;
                    dp[i][j] = ans;
                }

                // if next pattern char is not *:
                else
                {
                    if(match) dp[i][j] = dp[i+1][j+1];
                    else dp[i][j] = false;
                }
            }
        }

        return dp[0][0];
    }

    bool isMatch(string s, string p) {
        // vector<vector<int>> dp (s.size()+1, vector<int> (p.size()+1, -1));
        // return solve(s, p, 0, 0, dp);

        // Tabulation:
        return solve2(s, p);
    }
};