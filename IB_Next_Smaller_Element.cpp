vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st;
    vector<int> ans;
    for(auto i: A) {
        while(!st.empty() && st.top() >= i) st.pop();
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(i);
    }
    return ans;
}
