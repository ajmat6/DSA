class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // using stack and set:
        // stack<pair<char, int>> st;
        // set<pair<char, int>> sett;
        // for(int i=0; i<s.size(); i++) {
        //     if(s[i] == '(') st.push({s[i], i});
        //     else if(s[i] == ')') {
        //         if(!st.empty()) st.pop();
        //         else sett.insert({')', i});
        //     }
        // }

        // while(!st.empty()) {
        //     sett.insert(st.top());
        //     st.pop();
        // }
        // cout << sett.size() << endl;

        // string ans = "";
        // for(int i=0; i<s.size(); i++) {
        //     if(s[i] != '(' && s[i] != ')') ans += s[i];
        //     else if((s[i] == ')' || s[i] == '(') && sett.find({s[i], i}) == sett.end()) {
        //         ans += s[i];
        //         cout << s[i] << endl;
        //     } 
        // }
        // return ans;



        // using count:
        int open = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') open++;
            else if(s[i] == ')') {
                if(open > 0) open--;
                else  s[i] = '#';
            }
        }

        if(open > 0) {
            for(int i=s.size()-1; i>=0; i--) {
                if(s[i] == '(') {
                    s[i] = '#';
                    open--;
                    if(open == 0) break;
                }
            }
        }

        string ans = "";
        for(auto i: s) {
            if(i != '#') ans += i;
        }
        return ans;
    }
};