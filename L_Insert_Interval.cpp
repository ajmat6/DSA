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




        // // use merge sort and insert (same like merge intervals): nlogn time
        // in.push_back(ni);
        // sort(in.begin(), in.end());
        // vector<vector<int>> ans;
        // for(auto &i: in) {
        //     int size = ans.size();
        //     if(size == 0 || i[0] > ans[size-1][1]) ans.push_back(i);
        //     else ans[size-1][1] = max(ans[size-1][1], i[1]);
        // }
        // return ans;




        // using insert: n time:
        vector<vector<int>> ans; int i = 0;

        // insert intervals that are not coming in newInterval range (before it):
        for(; i < in.size() && in[i][1] < ni[0]; i++) ans.push_back(in[i]);

        // find merged interval
        int a = ni[0]; int b= ni[1];
        for(; i<in.size() && in[i][0] <= ni[1]; i++) {
            a = min(in[i][0], a);
            b = max(in[i][1], b);
        }
        ans.push_back({a, b}); // insert the merged interval

        // insert remaining interval:
        for(; i<in.size(); i++) ans.push_back(in[i]);
        return ans;
    }
};