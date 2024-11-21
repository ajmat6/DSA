class Solution {
    public:
    vector <int> maxOfMin(int heights[], int n) {
        stack<int> st;
        vector<int> ans (n, INT_MIN);
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[i] <= heights[st.top()]) {
                if(heights[i] < heights[st.top()]) {
                    int height = heights[st.top()];
                    st.pop();
                    int left = st.empty() ? -1 : st.top();
                    int windowWidth = i - left - 1;
                    ans[windowWidth - 1] = max(ans[windowWidth - 1], height);
                }
                else st.pop();
            }
            st.push(i);
        }
    
        while(!st.empty()) {
            int height = heights[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();
            int windowWidth = n - left - 1;
            ans[windowWidth - 1] = max(ans[windowWidth - 1], height);
        }
    
        for(int i=n-2; i>=0; i--) ans[i] = max(ans[i], ans[i + 1]);
        return ans;
    }
};