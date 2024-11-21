class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // using 5n time and 4n space:
        // int n = heights.size();
        // vector<int> right (n);
        // vector<int> left (n);

        // // finding right smaller element indexes:
        // stack<int> st;
        // for(int i=n-1; i>=0; i--) {
        //     while(!st.empty() && heights[i] <= heights[st.top()]) st.pop();
        //     if(!st.empty()) right[i] = st.top();
        //     else right[i] = n;
        //     st.push(i);
        // }

        // // finding left smaller element indexes:
        // stack<int> st2;
        // for(int i=0; i<n; i++) {
        //     while(!st2.empty() && heights[i] <= heights[st2.top()]) st2.pop();
        //     if(!st2.empty()) left[i] = st2.top();
        //     else left[i] = -1;
        //     st2.push(i);
        // }

        // int ans = INT_MIN;
        // // finding ans:
        // for(int i=0; i<n; i++) {
        //     int width = right[i] - left[i] - 1;
        //     ans = max(ans, heights[i] * width);
        // }
        // return ans;




        // using 2n time and n space:
        int ans = 0;
        stack<int> st;
        int n = heights.size();
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[i] <= heights[st.top()]) {
                if(heights[i] < heights[st.top()]) {
                    int height = heights[st.top()];
                    st.pop();
                    int left = st.empty() ? -1 : st.top();
                    ans = max(ans, height * (i - left - 1));
                }
                else st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) {
            int height = heights[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();
            ans = max(ans, height * (n - left - 1));
        }
        return ans;
    }
};

