class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // // using max heap: n^2logk where k can be at max n^2
        // priority_queue<int> pq;
        // int n = matrix.size();
        // int m = matrix[0].size();
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         pq.push(matrix[i][j]);
        //         if(pq.size() > k) pq.pop();
        //     }
        // }
        // return pq.top();




        // // using min heap: n + klogk time
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // // insert first column elements:
        // int n = matrix.size();
        // for(int i=0; i<min(n, k); i++) pq.push({matrix[i][0], i, 0});

        // int count = 0;
        // while(true) {
        //     auto topp = pq.top(); pq.pop();
        //     count += 1;
        //     if(count == k) return topp[0];
        //     if(topp[2] != matrix[0].size() - 1) pq.push({matrix[topp[1]][topp[2] + 1], topp[1], topp[2] + 1});
        // }

        // return 0;





        // using binary search: time is (log(maxElement - minElement) * nlogn) and const space:
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            // binary serach in each row to find no of elements lesser than or equal to mid:
            int count = 0;
            for(int i=0; i<n; i++) {
                int index = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                count += index;
            }

            if(count >= k) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};