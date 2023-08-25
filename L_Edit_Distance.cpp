class Solution {
public:
    // Recursion: Gives TLE
    int solve(string& w1, string& w2, int i, int j)
    {
        // when first string is less than the second string:
        if(i == w1.size())
        {
            return w2.size() - j;
        }

        // when second string has ended:
        if(j == w2.size())
        {
            return w1.size() - i;
        }

        // if current character match:
        if(w1[i] == w2[j]) return solve(w1, w2, i+1, j+1);

        int ans = INT_MAX;

        // if current character don't match call recursively for the three possible options:
        int insert = 1 + solve(w1, w2, i, j+1);
        int del = 1 + solve(w1, w2, i+1, j);
        int replace = 1 + solve(w1, w2, i+1, j+1);

        ans = min(ans, min(insert, min(del, replace)));
        return ans;
    }

    // Memorisation:
    int solve2(string& w1, string& w2, int i, int j, vector<vector<int>>& dp)
    {
        // when first string is less than the second string:
        if(i == w1.size())
        {
            return w2.size() - j;
        }

        // when second string has ended:
        if(j == w2.size())
        {
            return w1.size() - i;
        }

        // check for dp:
        if(dp[i][j] != -1) return dp[i][j];

        // if current character match:
        if(w1[i] == w2[j]) return solve2(w1, w2, i+1, j+1, dp);

        int ans = INT_MAX;

        // if current character don't match call recursively for the three possible options:
        int insert = 1 + solve2(w1, w2, i, j+1, dp);
        int del = 1 + solve2(w1, w2, i+1, j, dp);
        int replace = 1 + solve2(w1, w2, i+1, j+1, dp);

        ans = min(ans, min(insert, min(del, replace)));

        // storing in dp:
        dp[i][j] = ans;
        return dp[i][j];
    }

    // Tabulation:
    int solve3(string& w1, string& w2)
    {
        // Creating dp vector:
        vector<vector<int>> dp (w1.size()+1, vector<int> (w2.size()+1, 0));

        // Handling firsyt string less than second string length base case:
        for(int j=0; j<w2.length(); j++)
        {
            dp[w1.size()][j] = w2.size() - j;
        }

        // Handling second string ended case:
        for(int i=0; i<w1.length(); i++)
        {
            dp[i][w2.size()] = w1.size() - i;
        }

        // Handling rest of the cases:
        for(int i=w1.length()-1; i>=0; i--)
        {
            for(int j=w2.length()-1; j>=0; j--)
            {
                int ans = INT_MAX;

                // if current character match:
                if(w1[i] == w2[j]) 
                {
                    dp[i][j] = dp[i+1][j+1];
                    continue;
                }

                // if current character don't match:
                int insert = 1 + dp[i][j+1];
                int del = 1 + dp[i+1][j];
                int replace = 1 + dp[i+1][j+1];

                ans = min(ans, min(insert, min(del, replace)));
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    // Space Optimisation:
    int solve4(string& w1, string& w2)
    {
        // Creating dp vector:
        vector<int> curr (w1.size()+1, 0);
        vector<int> next (w2.size()+1, 0);

        // Handling first string less than second string length base case:
        for(int j=0; j<w2.length(); j++)
        {
            next[j] = w2.size() - j;
        }

        // Handling rest of the cases:
        for(int i=w1.length()-1; i>=0; i--)
        {
            for(int j=w2.length()-1; j>=0; j--)
            {
                // base case of recursion (second string ended):
                curr[w2.size()] = w1.size() - i;
                int ans = INT_MAX;

                // if current character match:
                if(w1[i] == w2[j]) 
                {
                    curr[j] = next[j+1];
                    continue;
                }

                // if current character don't match:
                int insert = 1 + curr[j+1];
                int del = 1 + next[j];
                int replace = 1 + next[j+1];

                ans = min(ans, min(insert, min(del, replace)));
                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }

    int minDistance(string word1, string word2) {
        // return solve(word1, word2, 0, 0);

        // Memorisation:
        // vector<vector<int>> dp (word1.size()+1, vector<int> (word2.size()+1, -1));
        // return solve2(word1, word2, 0, 0, dp);

        // Tabulation:
        return solve3(word1, word2);

        // Space Optimisation:
        return solve4(word1, word2);
    }
};