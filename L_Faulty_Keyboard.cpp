class Solution {
public:
    string reverse(string& s)
    {
        stack<char> st;
        for(int i=0; i<s.size(); i++)
        {
            st.push(s[i]);
        }
        
        string ans = "";
        while(!st.empty())
        {
            char c = st.top();
            st.pop();
            
            ans.push_back(c);
        }
        
        return ans;
    }
    string finalString(string s) {
        string ans = "";
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == 'i')
            {
                ans = reverse(ans);
            }
            
            else
            {
                ans += s[i];
            }
        }
        
        return ans;
    }
};