class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<pair<int, int>, int>> intervals;
        for(int i=0; i<n; i++) {
            int start = times[i][0];
            int end = times[i][1];
            intervals.push_back({{start, 1}, i});
            intervals.push_back({{end, -1}, i});
        }

        sort(intervals.begin(), intervals.end()); 

        priority_queue<int, vector<int>, greater<int>> chairs;
        for(int i=0; i<n; i++) chairs.push(i);

        unordered_map<int, int> mp;
        for(int i=0; i<intervals.size(); i++) {
            int time = intervals[i].first.first;
            int leaveOrJoin = intervals[i].first.second;
            int person = intervals[i].second;

            if(leaveOrJoin == 1) {
                if(person == targetFriend) return chairs.top();
                mp[person] = chairs.top();
                chairs.pop();
            }

            else {
                int leaveChair = mp[person];
                chairs.push(leaveChair);
                mp.erase(person);
            }
        }

        return 0;
    }
};