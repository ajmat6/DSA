class Solution {
public:
    #define pii pair<long long, long long>
    int mostBooked(int n, vector<vector<int>>& meet) {
        sort(meet.begin(), meet.end());
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> empty (n, 1); // 1 means empty
        vector<int> ans(n, 0);


        // Insert first meeting in room zero and insert it into pq:
        empty[0] = 0; ans[0] = 1;
        pq.push({meet[0][1], 0}); // <finishing time, room no>

        for(int i=1; i<meet.size(); i++) {
            int startTime = meet[i][0]; int endTime = meet[i][1];
            bool isAllocated = false;

            // first pop out all meeting whose finising time is less than or equal to startTime:
            while(!pq.empty() && pq.top().first <= startTime) {
                empty[pq.top().second] = 1;
                pq.pop();
            }

            // check for room availibility:
            for(int i=0; i<n; i++) {
                if(empty[i]) {
                    empty[i] = 0;
                    ans[i]++;
                    isAllocated = true;
                    pq.push({endTime, i});
                    break;
                }
            }

            if(isAllocated) continue;

            // if till here no room is allocated to the meeting then you have to wait till a room becomes empty:
            // pop first meeting from the pq and allocate the room taking into count the  delayed time of the meeting
            auto top = pq.top(); pq.pop();
            pq.push({top.first + (endTime - startTime), top.second}); // top.first + endtime - starttime is delayed time
            ans[top.second]++;
        }

        int maxMeetRoom = 0;
        int maxMeet = ans[0];
        for(int i=1; i<n; i++) {
            if(ans[i] > maxMeet) {
                maxMeetRoom = i;
                maxMeet = ans[i];
            }
        }

        return maxMeetRoom;
    }
};