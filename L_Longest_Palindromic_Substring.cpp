class Solution {
public:
    // using two pointers expanding around:
    string ans = "";
    void solve(string& s, int i, int j)
    {
        while(i >=0 && j < s.size() && s[i] == s[j])
        {
            i--;
            j++;
        }

        if(ans.size() < j - i)
            ans = s.substr(i+1, j-i-1);
    }

    // using recursion: Brute force
    bool isPalindrome(string& s, int i, int j)
    {
        while(i <= j)
        {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    // brute force: O(n^3) TC
    void recursive(string& s, int i, int j)
    {
        // Base case:
        if(j == s.size()) return;

        // if string is palindrome b/w i and j, then update ans and then call:
        if(isPalindrome(s, i, j))
        {
            if(ans.size() < j-i+1) 
            {
                // updating ans:
                ans = s.substr(i, j-i+1);
            }

            recursive(s, i, j+1);
        }

        else
        {
            recursive(s, i, j+1);
        }
    }


    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        for(int i=0; i<s.size(); i++)
        {
            solve(s, i, i); // for cases like: aabaa
            solve(s, i, i+1); // for cases like aabbaa 

            // 2nd approach
            // recursive(s, i, i);
        }

        return ans;
    }
};