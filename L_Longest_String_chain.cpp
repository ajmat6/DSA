class Solution {
public:
    static bool compare(string& a, string& b)
    {
        return a.size() < b.size();
    }

    // to make sure that curr word is greater than previous word:
    bool check(string& a, string& b)
    {
        if(a.size()+1 != b.size()) return false;

        int i = 0;
        int j = 0;

        while(j < b.size())
        {
            if(a[i] == b[j])
            {
                i++;
                j++;
            }

            else
            {
                j++;
            }
        }

        if(i == a.size() && j == b.size()) return true;
        else return false;
    }

    // Recursive: 
    int solve(vector<string>& words, int prevIndex, int currIndex)
    {
        if(currIndex >= words.size()) return 0;

        // include current word:
        int include = 0;
        int exclude = 0;

        if(prevIndex == -1 || check(words[prevIndex], words[currIndex]))
        {
            include = 1 + solve(words, currIndex, currIndex+1);
        }

        // exclude current word:
        exclude = 0 + solve(words, prevIndex, currIndex+1);

        int ans = max(include, exclude);
        return ans;
    }

    // Memorisation: 
    int solve2(vector<string>& words, int prevIndex, int currIndex, vector<vector<int>>& dp)
    {
        if(currIndex >= words.size()) return 0;

        // check for dp:
        if(dp[prevIndex+1][currIndex] != -1) return dp[prevIndex+1][currIndex];

        // include current word:
        int include = 0;
        int exclude = 0;

        if(prevIndex == -1 || check(words[prevIndex], words[currIndex]))
        {
            include = 1 + solve2(words, currIndex, currIndex+1, dp);
        }

        // exclude current word:
        exclude = 0 + solve2(words, prevIndex, currIndex+1, dp);

        int ans = max(include, exclude);
        dp[prevIndex+1][currIndex] = ans;
        return ans;
    }

    // Tabulation:
    int solve3(vector<string>& words)
    {
        vector<vector<int>> dp (words.size()+1, vector<int> (words.size()+1, 0));

        for(int prevIndex=words.size()-2; prevIndex>=-1; prevIndex--)
        {
            for(int currIndex=words.size()-1; currIndex>=0; currIndex--)
            {
                // include current word:
                int include = 0;
                int exclude = 0;

                if(prevIndex == -1 || check(words[prevIndex], words[currIndex]))
                {
                    include = 1 + dp[currIndex+1][currIndex+1];
                }

                // exclude current word:
                exclude = 0 + dp[prevIndex+1][currIndex+1];

                int ans = max(include, exclude);
                dp[prevIndex+1][currIndex] = ans;
            }
        }

        return dp[0][0];
    }

    int longestStrChain(vector<string>& words) {
        // sorting array in increasing length:
        sort(words.begin(), words.end(), compare);

        // return solve(words, -1, 0);

        // Memorisation:
        // vector<vector<int>> dp (words.size()+1, vector<int> (words.size()+1, -1));
        // return solve2(words, -1, 0, dp);

        // Tabulation:
        return solve3(words);
    }

};