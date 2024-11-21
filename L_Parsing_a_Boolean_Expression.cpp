class Solution {
public:
    bool solveNot(int& index, string& exp) {
        bool ans;
        if(exp[index] == '!') ans = !solveNot(index+=2, exp);
        else if(exp[index] == '|') ans = !solveOrAnd(index += 2, exp, true);
        else if(exp[index] == '&') ans = !solveOrAnd(index += 2, exp, false);
        else if(exp[index] == 't') ans = false;
        else ans = true;
        index++; // as current index points to ')'
        return ans;
    }

    bool solveOrAnd(int& index, string& exp, bool isOr) {
        int ans = -1;
        while(exp[index] != ')') {
            if(exp[index] == ',') {
                index++;
                continue;
            }

            bool res;
            if(exp[index] == 't') res = true;
            else if(exp[index] == 'f') res = false;
            else if(exp[index] == '|') res = solveOrAnd(index += 2, exp, true);
            else if(exp[index] == '&') res = solveOrAnd(index += 2, exp, false);
            else res = solveNot(index += 2, exp);

            if(ans == -1) ans = res;
            else {
                if(isOr) ans |= res;
                else ans &= res;
            }
            index++;
        }
        return ans;
    }

    bool parseBoolExpr(string exp) {
        // without stack and using recursion: n time and n stack space:
        int index = 0;
        if(exp[index] == '!') return solveNot(index += 2, exp);
        else if(exp[index] == '|') return solveOrAnd(index += 2, exp, true);
        else if(exp[index] == '&') return solveOrAnd(index += 2, exp, false);
        else if(exp[index] == 't') return true;
        else return false;






        // using stack: n time and n space:
        stack<char> st;
        for(int i=0; i<exp.size(); i++) {
            if(exp[i] == '(' || exp[i] == ',') continue;
            if(exp[i] != ')') st.push(exp[i]);
            else {
                bool isTrue = false;
                bool isFalse = false;
                while(!st.empty() && (st.top() == 't' || st.top() == 'f')) {
                    if(st.top() == 't') isTrue = true;
                    else isFalse = true;
                    st.pop();
                }

                char op = st.top(); st.pop();
                if(op == '!') st.push(isTrue ? 'f' : 't');
                else if(op == '|') st.push(isTrue ? 't' : 'f');
                else st.push(isFalse ? 'f' : 't');
            }
        }

        return st.top() == 't' ? true : false;
    }
};