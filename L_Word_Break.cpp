class Solution {
public: 
    bool recursive(int i,set<string>&st,string s)
    {
        if(i >= s.size()) return true;

        for(int j=i;j<s.size();j++){
            string temp=s.substr(i,j-i+1);
            if(st.find(temp)!=st.end() && recursive(j+1,st,s)){
                return true;
            }
        }
        return false;
    }

    bool Memo(int i,set<string>&st,string s, vector<int>& dp)
    {
        if(i >= s.size()) return true;

        // check for dp:
        if(dp[i] != -1) return dp[i];

        for(int j=i;j<s.size();j++){
            string temp=s.substr(i,j-i+1);
            if(st.find(temp)!=st.end() && Memo(j+1,st,s, dp)){
                return dp[i] = true;
            }
        }


        return dp[i] = false;
    }

    bool Tab(set<string>&st,string s)
    {
        vector<bool> dp (s.size()+1, false);

        // Handle base case:
        dp[s.size()] = true;

        for(int i=s.size()-1; i>=0; i--)
        {
            for(int j=i;j<s.size();j++)
            {
                string temp=s.substr(i,j-i+1);
                if(st.find(temp)!=st.end() && dp[j+1])
                {
                    dp[i] = true;
                }
            }

        }

        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict)
    {
        set<string>st;
        for(auto x:wordDict){
            st.insert(x);
        }
        // return recursive(0,st, s);

        // Memorisaiton:
        // vector<int> dp (s.size()+1, -1);
        // return Memo(0,st, s, dp);

        // Tabulation:
        return Tab(st, s);
    }
};