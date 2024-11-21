class Solution {
public:
    int minSwaps(string s) {
        // using stack: n time and n space:
        // stack<char> st;
        // for(auto i: s) {
        //     if(i == '[') st.push(i);
        //     else if(i == ']' && !st.empty() && st.top() == '[') st.pop();
        //     else st.push(i);
        // }

        // int ans = st.size() / 4;
        // if(st.size() % 4 != 0) ans += 1;
        // return ans;




        // using count: n time and const space:
        int open = 0;
        int ans = 0;
        for(auto i: s) {
            if(i == '[') open++;
            else {
                if(open) open--;
                else {
                    ans++;
                    open++; // closed is swapped with some open so open at current index increase
                }
            }
        }
        return ans;
    }
};