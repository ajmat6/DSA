class Solution {
public:
    void solve(string& s, int index, set<string>& st, vector<string>& ans, string temp)
    {
        if(index == s.size())
        {
            temp.pop_back(); // last space remove
            ans.push_back(temp);
        }

        string str = "";
        for(int i=index; i<s.size(); i++)
        {
            str.push_back(s[i]);
            if(st.find(str) != st.end())
            {
                solve(s, i+1, st, ans, temp + str + " ");
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Mapping dictionary word:
        set<string> st;
        for(auto i: wordDict)
        {
            st.insert(i);
        }

        vector<string> ans;
        string temp = "";
        solve(s, 0, st, ans, temp);

        return ans;
    }
};