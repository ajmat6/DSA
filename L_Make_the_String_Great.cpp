class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto i: s) {
            if(!st.empty()) {
                if(i - 'a' <= 25 && st.top() - 'A' == i - 'a') st.pop();
                else if(i - 'A' <= 25 && st.top() - 'a' == i - 'A') st.pop();
                else st.push(i);
            }
            else st.push(i);
        }

        s = "";
        while(!st.empty()) {
            s = st.top() + s;
            st.pop();
        }

        return s;
    }
};