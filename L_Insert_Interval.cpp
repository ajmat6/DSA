class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // if(intervals.size() == 0)
        // {
        //     intervals.push_back(newInterval);
        //     return intervals;
        // }

        // stack<vector<int>> st;

        // int n = intervals.size();
        // int flag = 1;
        // for(int i=n-1; i>=0; i--)
        // {
        //     vector<int> temp = intervals[i];
        //     if(temp[0] <= newInterval[0] && flag == 1)
        //     {
        //         st.push(newInterval);
        //         flag = 0;
        //     }
        //     st.push(temp);
        // }

        // // if new interval is shortest of all:
        // if(flag == 1)
        // {
        //     st.push(newInterval);
        // }

        // intervals.clear(); // clear intervals vector

        // while(!st.empty())
        // {
        //     vector<int> temp = st.top();
        //     st.pop();
        //     intervals.push_back(temp);
        // }

        // int index = 0;
        // while(1)
        // {
        //     int size = intervals.size();
        //     if(index == size) break;

        //     if(index != 0 && intervals[index][0] <= intervals[index-1][1])
        //     {
        //         intervals[index-1][1] = max(intervals[index][1], intervals[index-1][1]);
        //         intervals.erase(intervals.begin() + index);
        //     }

        //     else
        //     {
        //         index++;
        //     }
        // }

        // return intervals;


        // 2nd Approach: Merge intervals:
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(auto i: intervals)
        {
            int size = ans.size();

            // first value to insert in the and:
            if(size == 0) ans.push_back(i);

            // case like (0, 5) and (3, 4) where (3, 4) is already in the range of (0, 5):
            else if(ans[size-1][1] >= i[0] && ans[size-1][1] >= i[1])
            {
                continue;
            }

            // case like (0, 5) and (4, 6) or (0, 5) and (5, 6):
            else if(ans[size-1][1] >= i[0] && ans[size-1][1] < i[1])
            {
                ans[size-1][1] = i[1];
            }

            // rest of the cases:
            else
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};