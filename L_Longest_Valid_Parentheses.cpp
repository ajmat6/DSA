class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0) return 0;

        stack<int> st;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(')
            {
               st.push(i);
            }

            else
            {
                if(!st.empty() && s[st.top()] == '(')
                {
                    st.pop();
                }

                else st.push(i);
            }
        }

        if(st.size() == 0) return s.size();

        int ans = 0;
        int low = 0;
        int high = s.size();

        while(!st.empty())
        {
            low = st.top();
            st.pop();
            ans = max(ans, high - low - 1);
            high = low;
        }
        // check for lower range at last:
        ans = max(ans, high);
        return ans;
    }
};