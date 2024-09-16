class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // using space: nlogn time and n space:
        // int n = arr.size();
        // vector<pair<int, int>> time;
        // for(int i=0; i<n; i++) {
        //     time.push_back({arr[i], dep[i]});
        // }
        // sort(time.begin(), time.end());
        
        // int ans = 0;
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for(int i=0; i<n; i++) {
        //     int arrival = time[i].first;
        //     int departure = time[i].second;
            
        //     while(!pq.empty() && pq.top() < arrival) pq.pop();
        //     pq.push(departure);
            
        //     ans = max(ans, (int)pq.size());
        // }
        
        // return ans;
        
        
        
        // without using space: nlogn time and constant space:
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int maxPlat = 0;
        int currPlat = 0;
        int left = 0;
        int right = 0;
        while(left < n && right < n) {
            if(arr[left] <= dep[right]) {
                currPlat++;
                maxPlat = max(maxPlat, currPlat);
                left++;
            }
            
            else {
                currPlat--;
                right++;
            }
        }
        
        return maxPlat;
    }
};