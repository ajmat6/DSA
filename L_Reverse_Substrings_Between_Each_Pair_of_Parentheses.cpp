class Solution {
public:
    int index = 0;
    string solve(string& s) {
        string ans = "";
        while(index < s.size()) {
            if(s[index] == ')') {
                reverse(ans.begin(), ans.end());
                index++;
                return ans;
            }
            else if(s[index] == '(') {
                index++;
                string temp = solve(s);
                ans += temp;
            }
            else ans += s[index++];
        }
        return ans;
    }

    string reverseParentheses(string s) {
        // with recursion:
        return solve(s);
        // without recursion:
        string ans = "";
        for(int index=0; index<s.size(); index++) {
            while(index < s.size() && s[index] != '(') ans.push_back(s[index++]);

            if(index < s.size()) {
                stack<char> st;
                st.push(s[index++]);

                while(index < s.size()) {
                    if(s[index] != ')') st.push(s[index]);
                    else {
                        string temp = "";
                        while(st.top() != '(') {
                            temp.push_back(st.top());
                            st.pop();
                        }

                        st.pop();

                        if(st.empty()) {
                            ans += temp;
                            break;
                        }
                        else {
                            int i = 0;
                            while(i < temp.size()) {
                                st.push(temp[i]);
                                i++;
                            }
                        }
                    }
                    index++;
                }
            }
        }
        return ans;
    }
};