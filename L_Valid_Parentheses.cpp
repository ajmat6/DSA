class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i: s) {
            if(i == '(' || i == '{' || i == '[') st.push(i);
            else {
                if(st.size() == 0) return false;
                else {
                    cout << st.top() << " " << i << endl;
                    if(i == ')' && st.top() != '(') return false;
                    else if(i == '}' && st.top() != '{') return false;
                    else if(i == ']' && st.top() != '[') return false;
                    else st.pop();
                }
            }
        }

        if(st.size() != 0) return false;
        return true;
    }
};