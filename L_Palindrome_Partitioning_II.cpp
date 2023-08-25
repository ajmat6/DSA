class Solution {
public:
    // function to check palindrome:
    bool checkForPalindrome(string& s, int i, int j)
    {
        while(i < j)
        {
            if(s[i] != s[j]) return false;
            
            i++;
            j--;
        }

        return true;
    }

    int recursion(string& s, int i, int j)
    {
        // checking for palidrome first as if whole range is palindromic then we don't need to check as we need min palindromic partitions:
        if(i >= j || checkForPalindrome(s, i, j)) return 0;

        int ans = INT_MAX;
        for(int index=i; index<j; index++)
        {
            if(checkForPalindrome(s, i, index))
            {
                int possible = 1 + recursion(s, index+1, j);
                ans = min(ans, possible);
            }
        }

        return ans;
    }

    int memo(string& s, int i, int j, vector<int>& dp)
    {
        // checking for palidrome first as if whole range is palindromic then we don't need to check as we need min palindromic partitions:
        if(i >= j || checkForPalindrome(s, i, j)) return 0;

        // check for dp:
        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for(int index=i; index<j; index++)
        {
            if(checkForPalindrome(s, i, index))
            {
                int possible = 1 + memo(s, index+1, j, dp);
                ans = min(ans, possible);
            }
        }

        // storing in dp:
        dp[i] = ans;

        return ans;
    }

    int tab(string& s)
    {
        int j = s.size();

        vector<int> dp (j+1, 0);

        for(int i=j-1; i>=0; i--)
        {
            // checking for palidrome first as if whole range is palindromic then we don't need to check as we need min palindromic partitions:
            // if(checkForPalindrome(s, i, j)) continue;

            int ans = INT_MAX;
            for(int index=i; index<j; index++)
            {
                if(checkForPalindrome(s, i, index))
                {
                    int possible = 1 + dp[index+1];
                    ans = min(ans, possible);
                }
            }

            // storing in dp:
            dp[i] = ans;
        }


        return dp[0]-1;
    }

    int minCut(string s) {
        int n = s.size();
        // return recursion(s, 0, n-1);

        // vector<int> dp (n+1, -1);
        // return memo(s, 0, n-1, dp);

        return tab(s);
    }
};