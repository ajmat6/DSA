class Solution {
public:
    // Recursion: Gives TLE
    int solve(string& s, int index)
    {
        // Base Case
        if(index == s.size()) return 1;

        int ans = 0;
        int endIndex = 0; // to find substring
        for(int i=index; i<s.size() && i<=index+2; i++)
        {
            endIndex++;
            // checking each possible substring:
            string str = s.substr(index, endIndex); 

            // if substring size is 1 then its value should not be zero:
            if(str.size() == 1 && stoi(str) > 0)
            {
                ans += solve(s, i+1);
            }

            // if substring size is 2 then its value is b/w 10 and 26:
            else if(str.size() == 2 && stoi(str) >= 10 && stoi(str) <= 26)
            {
                ans+= solve(s, i+1);
            }
        }
        
        return ans;
    }

    // Memorisation:
    int solveMem(string& s, int index, vector<int>& dp)
    {
        if(index == s.size()) return 1;

        // check for dp:
        if(dp[index] != -1) return dp[index];

        int ans = 0;
        int endIndex = 0;
        for(int i=index; i<s.size() && i<=index+2; i++)
        {
            endIndex++;
            string str = s.substr(index, endIndex);

            if(str.size() == 1 && stoi(str) > 0)
            {
                ans += solveMem(s, i+1, dp);
            }

            else if(str.size() == 2 && stoi(str) >= 10 && stoi(str) <= 26)
            {
                ans+= solveMem(s, i+1, dp);
            }
        }

        // storing ans in dp:
        dp[index] = ans;
        
        return ans;
    }

    // Tabulation:
    int solveTab(string& s)
    {
        vector<int> dp(s.size()+1, 0);

        // base case handle:
        dp[s.size()] = 1;

        for(int index=s.size()-1; index>=0; index--)
        {
            int ans = 0;
            int endIndex = 0;
            for(int i=index; i<s.size() && i<=index+2; i++)
            {
                endIndex++;
                string str = s.substr(index, endIndex);

                if(str.size() == 1 && stoi(str) > 0)
                {
                    ans += dp[i+1];
                }

                else if(str.size() == 2 && stoi(str) >= 10 && stoi(str) <= 26)
                {
                    ans+= dp[i+1];
                }
            }

            // storing ans in dp:
            dp[index] = ans;
        }
        
        return dp[0];
    }

    // Space Optimised:
    int solveSO(string& s)
    {
        // Variables for space optimisation:
        int curr = 0;
        int next1 = 0;
        int next2 = 0;
        int next3 = 0;

        // base case handle:
        next1 = 1;

        for(int index=s.size()-1; index>=0; index--)
        {
            int ans = 0;
            int endIndex = 0;
            for(int i=index; i<s.size() && i<index+2; i++)
            {
                endIndex++;
                string str = s.substr(index, endIndex);

                if(str.size() == 1 && stoi(str) > 0)
                {
                    ans += next1;
                }

                else if(str.size() == 2 && stoi(str) >= 10 && stoi(str) <= 26)
                {
                    ans+= next2;
                }
            }

            // storing ans in dp:
            curr = ans;
            next3 = next2;
            next2 = next1;
            next1 = curr;
        }
        
        return curr;
    }

    int numDecodings(string s) {
        // return solve(s, 0);

        // Memorisation:
        // vector<int> dp (s.size(), -1);
        // return solveMem(s, 0, dp);

        // Tabulation:
        // return solveTab(s);

        // Space Optimisation:
        return solveSO(s);
    }
};