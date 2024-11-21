class Solution {
public:
    int minAddToMakeValid(string s) {
        // stack<char> st;
        // for(auto i: s) {
        //     if(!st.empty() && st.top() == '(' && i == ')') st.pop();
        //     else st.push(i);
        // }
        // return st.size();


        int open = 0;
        int closed = 0;
        for(auto i: s) {
            if(i == '(') open++;
            else {
                if(open) open--;
                else closed++;
            }
        }
        return open + closed;
    }
};