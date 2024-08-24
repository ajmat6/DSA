class Solution {
public:
    string removeKdigits(string num, int k) {
        // montonic stack till k != 0:
        stack<char> st;
        for(auto i: num) {
            while(k > 0 && !st.empty() && st.top() > i) {
                st.pop();
                k--;
            }
            st.push(i);
        }

        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // construct ans string from stack:
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // removing starting zeros:
        int i = 0;
        while(i < ans.size() && ans[i] == '0') i++;
        if(i < ans.size()) return ans.substr(i);
        else return "0";
    }
};