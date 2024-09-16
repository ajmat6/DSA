class Solution {
  public:
    bool check(vector<int>& stations, int k, int n, double dist) {
        int count = 1;
        double prev = stations[0];
        for(int i=1; i<n; i++) {
            while(prev + dist < stations[i]) {
                count += 1;
                prev = prev + dist;
            }
            count += 1;
            prev = stations[i];
        }
        if(count <= n + k) return true;
        return false;
    }
    
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // brute: calculating where curr new station to be put bases on max adjacent distance: time is k * n and space is n
        // int n = stations.size();
        // vector<int> howManyB(n - 1, 0);
        
        // for(int i=0; i<k; i++) {
        //     double maxDiff = -1;
        //     int maxDiffIndex = -1;
        //     for(int j=0; j<n-1; j++) {
        //         double diff = (stations[j + 1] - stations[j]) / (double)(howManyB[j] + 1);
        //         if(diff > maxDiff) {
        //             maxDiff = diff;
        //             maxDiffIndex = j;
        //         }
        //     }
        //     howManyB[maxDiffIndex]++;
        // }
        
        // double ans = INT_MIN;
        // for(int i=0; i<n-1; i++) {
        //     double diff = (stations[i + 1] - stations[i]) / (double)(howManyB[i] + 1);
        //     ans = max(ans, diff);
        // }
        // return ans;
        
        
        
        // better: reducing the time required to fetch the max adjacent distance using priority queue:
        // int n = stations.size();
        // vector<int> howManyB(n - 1, 0);
        
        // priority_queue<pair<double, int>> pq;
        // for(int i=0; i<n-1; i++) {
        //     pq.push({(double)(stations[i + 1] - stations[i]), i});
        // }
        
        // for(int i=0; i<k; i++) {
        //     auto topp = pq.top(); pq.pop();
        //     int index = topp.second;
        //     howManyB[index]++;
        //     double newDist = (stations[index + 1] - stations[index]) / (double)(howManyB[index] + 1);
        //     pq.push({newDist, index});
        // }
        
        // return pq.top().first + 1e-4;
        
        
        
        
        // optimal: using binary search: n + log(maxDiff) * n  time and constant space:
        double low = 0.01; // minimum distance b/w two adjacent stations that can be maximum
        double high = -1; 
        for(int i=1; i<stations.size(); i++) {
            high = max(high, double(stations[i] - stations[i - 1]));
        }
        double ans = 0;
        while((high - low) >= 1e-4) { // in floating nos binary search the difference b/w low and high should be greater than the precision asked
            double mid = (double)(low + (high - low) / 2.0);
            if(check(stations, k, stations.size(), mid)) {
                ans = mid;
                high = mid;
            }
            else low = mid; // in floating nos bs, don't do low = mid + 0.01 or like this
        }
        return ans;
    }
};