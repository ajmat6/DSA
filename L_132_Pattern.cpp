class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int thirdNo = INT_MIN;

        for(int i=nums.size()-1; i>=0; i--)
        {
            if(nums[i] < thirdNo) return true;
            // here if j's value is found
            while(!st.empty() && st.top() < nums[i])
            {
                // then uska previous k's value thi:
                thirdNo = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }

        return false;
    }
};