class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(auto i: intervals)
        {
            int size = ans.size();
            if(size == 0) ans.push_back(i);

            else if(ans[size-1][1] >= i[0] && ans[size-1][1] < i[1])
            {
                ans[size-1][1] = i[1];
            }

            else if(ans[size-1][1] >= i[0] && ans[size-1][1] >= i[1])
            {
                
            }

            else
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};