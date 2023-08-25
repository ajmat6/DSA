class Solution {
public:
    void solve(int n, int countOpen, int countClose, string& temp, vector<string>& ans)
    {
        if(countOpen == n && countClose == n)
        {
            ans.push_back(temp);
            return;
        }

        if(countOpen < n)
        {
            temp.push_back('(');
            solve(n, countOpen+1, countClose, temp, ans);
            temp.pop_back();
        }

        if(countClose < countOpen)
        {
            temp.push_back(')');
            solve(n, countOpen, countClose+1, temp, ans);
            temp.pop_back();
        }

        return;
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(n, 0, 0, temp, ans);
        return ans;
    }
};