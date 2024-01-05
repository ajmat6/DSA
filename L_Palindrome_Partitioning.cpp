class Solution {
public:
    bool isPalindrome(int start, int end, string& s)
    {
        while(start <= end)
        {
            if(s[start] != s[end]) return false;
            else
            {
                start++;
                end--;
            }
        }

        return true;
    }

    void solve(string& s, vector<vector<string>>& ans, vector<string>& temp, int index)
    {
        if(index == s.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i=index; i<s.size(); i++)
        {
            if(isPalindrome(index, i, s))
            {
                temp.push_back(s.substr(index, i - index + 1));
                solve(s, ans, temp, i+1);
                temp.pop_back();
            }
        }

        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, ans, temp, 0);
        return ans;
    }
};