class Solution {
public:
    int maxDepth(string s) {
        // using stack:
        // stack<char> st;
        // int ans = 0; int curr = 0;
        // for(auto i: s) {
        //     if(i == '(') {
        //         st.push(i);
        //         curr += 1;
        //         ans = max(ans, curr);
        //     }
        //     else if(i == ')') {
        //         st.pop();
        //         curr--;
        //     }
        // }
        // return ans;

        int ans = 0, curr = 0;
        for(auto i: s) {
            if(i == '(') {
                curr += 1;
                ans = max(ans, curr);
            }
            else if(i == ')') curr--;
        }
        return ans;
    }
};