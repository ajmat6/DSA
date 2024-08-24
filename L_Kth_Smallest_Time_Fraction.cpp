class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // using brute force: time (n^2 + n^2log(n^2)) and space is n^2:
        // vector<vector<double>> temp;
        // for(int i=0; i<arr.size(); i++) {
        //     for(int j=i+1; j<arr.size(); j++) temp.push_back({(double)arr[i] / (arr[j] * 1.0), arr[i] * 1.0, arr[j] * 1.0});
        // }

        // sort(temp.begin(), temp.end());
        // vector<double> ans = temp[k - 1];
        // cout << ans[1] << " " << ans[2];
        // return {(int)ans[1], (int)ans[2]};




        // using max heap:time is n^2log(k) and space is k
        // priority_queue<pair<double, pair<int, int>>> pq;

        // int n = arr.size();
        // for(int i=0; i<n; i++) {
        //     for(int j=i+1; j<n; j++) {
        //         double fraction = arr[i] * 1.0 / arr[j];
        //         pq.push({fraction, {i, j}});
        //         if(pq.size() > k) pq.pop();
        //     }
        // }
        // return {arr[pq.top().second.first], arr[pq.top().second.second]};




        // using min heap: time is n + klogk and k space:
        // int n = arr.size();
        // priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

        // for(int i=0; i<min(n, k); i++) {
        //     double value = arr[i] * 1.0 / arr[n - 1];
        //     pq.push({value, {i, n - 1}});
        // }

        // for(int i=0; i<k-1; i++) {
        //     auto topp = pq.top(); pq.pop();
        //     int row = topp.second.first; int col = topp.second.second;
        //     if(col != 0) {
        //         double value = arr[row] * 1.0 / arr[col - 1];
        //         pq.push({value, {row, col - 1}});
        //     }
        // }

        // pair<double, pair<int, int>> ans = pq.top();
        // return {arr[ans.second.first], arr[ans.second.second]};





        // using binary search: nlogn^2 time complexity and const space:
        double low = 0.0;
        double high = 1.0;
        int n = arr.size();

        while(low < high) {
            double mid = low + (high - low) / 2;

            // check if there are exactly k smaller elements than mid in arr:
            int j = 1;
            int count = 0; int ans1 = 0; int ans2 = 0; double maxRatio = 0.0;
            for(int i=0; i<n; i++) {
                while(j < n && arr[i]  > arr[j] * mid) j++;
                count += n - j;

                // update the ans values(indexes) if current element ratio is greater than maxRation (as it can give me result)
                if(j < n && arr[i] * 1.0 / arr[j] > maxRatio) {
                    maxRatio = arr[i] * 1.0 / arr[j];
                    ans1 = i;
                    ans2 = j;
                }
            }

            if(count == k) return {arr[ans1], arr[ans2]};
            else if(count < k) low = mid;
            else high = mid;
        }

        return {0, 0};
    }
};