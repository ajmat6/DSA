class Solution {
public:
    int recursive(string& s, set<string>& st, int index, int& n)
    {
        // Base case:
        if(index == s.size()) return 0;

        int ans = INT_MAX;
        ans = min(ans, 1 + recursive(s, st, index+1, n));
        for(int i=index; i<n; i++)
        {
            cout << i << " ";
            string temp = s.substr(index, i-index+1);
            if(st.find(temp) != st.end())
            {
                ans = min(ans, recursive(s, st, i+1, n));
            }

        }

        return ans;
    }

    // Memorisation:
    int memo(string& s, set<string>& st, int index, vector<int>& dp)
    {
        // Base case:
        if(index == s.size()) return 0;

        if(dp[index] != -1) return dp[index];

        int ans = INT_MAX;
        ans = min(ans, 1 + memo(s, st, index+1, dp));
        for(int i=index; i<s.size(); i++)
        {
            string temp = s.substr(index, i-index+1);
            if(st.find(temp) != st.end())
            {
                ans = min(ans, memo(s, st, i+1, dp));
            }

        }

        dp[index] = ans;

        return ans;
    }

    // Tabulation:
    int tab(string& s, set<string>& st)
    {
        vector<int> dp (s.size()+1, 0);

        for(int index=s.size()-1; index>=0; index--)
        {
            int ans = INT_MAX;
            ans = min(ans, 1 + dp[index+1]);
            for(int i=index; i<s.size(); i++)
            {
                string temp = s.substr(index, i-index+1);
                if(st.find(temp) != st.end())
                {
                    ans = min(ans, dp[i+1]);
                }

            }

            dp[index] = ans;
        }

        return dp[0];
    }

    int minExtraChar(string& s, vector<string>& dictionary) {
        // mapping of dictionary words:
        set<string> st;
        for(auto &x: dictionary)
        {
            st.insert(x);
        }

        // Recursion:
        // int n = s.size();
        // return recursive(s, st, 0, n);

        // vector<int> dp(s.size(), -1);
        // return memo(s, st, 0, dp);

        return tab(s, st);
    }
};