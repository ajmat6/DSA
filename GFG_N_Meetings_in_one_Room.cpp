// class Solution {
//   public:
//     static bool cmp(pair<int, int>& a, pair<int, int>& b) {
//         return a.second < b.second;
//     }
    
//     int maxMeetings(int n, int start[], int end[]) {
//         vector<pair<int, int>> meet;
//         for(int i=0; i<n; i++) meet.push_back({start[i], end[i]});
        
        
//         sort(meet.begin(), meet.end(), cmp);
        
//         int ans = 1;
//         int prevEndTime = meet[0].second;
//         for(int i=1; i<n; i++) {
//             if(meet[i].first > prevEndTime) {
//                 ans +=1;
//                 prevEndTime = meet[i].second;
//             }
//         }
//         return ans;
//     }
// };




class Solution {
  public:
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int, int>> meet;
        for(int i=0; i<n; i++) meet.push_back({end[i], start[i]});
        
        sort(meet.begin(), meet.end());
        
        int ans = 0;
        int prevEndTime = 0;
        for(int i=0; i<n; i++) {
            if(meet[i].second > prevEndTime) {
                ans +=1;
                prevEndTime = meet[i].first;
            }
        }
        return ans;
    }
};