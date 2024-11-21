class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // tc is O(3n) and space is n at worst case:
        int ans = 0;
        stack<int> st;
        int n = nums.size();
        for(int i=n-1; i>=0; i--) {
            if(st.empty() || nums[i] > nums[st.top()]) st.push(i);
        }

        for(int i=0; i<n && !st.empty(); i++) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                ans = max(ans, st.top() - i);
                st.pop();
            }
        }
        return ans;
    }
};