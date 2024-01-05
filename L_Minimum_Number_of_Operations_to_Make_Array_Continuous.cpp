class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st;
        for(auto i: nums)
        {
            if(st.find(i) == st.end()) st.insert(i);
        }

        vector<int> temp;
        for(auto i: st)
        {
            cout << i << " ";
            temp.push_back(i);
        }

        // sliding window on temp array:
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i <= j && j < temp.size())
        {
            if(temp[j] - temp[i] <= nums.size() - 1)
            {
                j++;
            }

            else
            {
                ans = max(ans, j - i);
                i++;
            }
        }
        ans = max(ans, j - i);

        cout << ans;

        return nums.size() - ans;
    }
};