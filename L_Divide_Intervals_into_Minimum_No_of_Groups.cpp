class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // using line sweep algo:
        // map<int, int> mp;
        // for(auto i: intervals) {
        //     mp[i[0]]++;
        //     mp[i[1] + 1]--;
        // }

        // int curr = 0;
        // int ans = 0;
        // for(auto i: mp) {
        //     curr += i.second;
        //     ans = max(ans, curr);
        // }
        // return ans;



        // // using array: n + n + maxNum time and maxNum is the space:
        // int maxi = 0;
        // for(auto i: intervals) maxi = max(maxi, i[1]);
        
        // vector<int> freq (maxi + 2);
        // for(auto i: intervals) {
        //     freq[i[0]]++;
        //     freq[i[1] + 1]--;
        // }

        // int curr = 0;
        // int ans = 0;
        // for(auto i: freq) {
        //     curr += i;
        //     ans = max(ans, curr);
        // }
        // return ans;



        // using start and end time:
        // int n = intervals.size();
        // vector<int> start, end;
        // for(auto i: intervals) {
        //     start.push_back(i[0]);
        //     end.push_back(i[1] + 1);
        // }
        // sort(start.begin(), start.end());
        // sort(end.begin(), end.end());

        // int i = 0, j = 0, ans = 0, count = 0;
        // while(i < n) {
        //     if(start[i] < end[j]) {
        //         i++;
        //         count++;
        //         ans = max(ans, count);
        //     }
        //     else if(end[j] > start[i]) {
        //         j++;
        //         count--;
        //     }
        //     else {
        //         i++;
        //         j++;
        //     }
        // }
        
        // return ans;


        // using heaps:
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        int ans = 0;
        for(auto i: intervals) {
            int start = i[0];
            int end = i[1];
            while(!pq.empty() && pq.top() < start) pq.pop();
            pq.push(end);
            ans = max(ans, int(pq.size()));
        }
        return ans;
    }
};