class Solution {
public:
    void heapPush(int a, int b, priority_queue<pair<double, int>>& pq, int index) {
        double diff = (double) (a + 1) / (b + 1) - (double) a / b; // gain ratio 
        pq.push({diff, index});
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, int>> pq;
        for(int i=0; i<n; i++) heapPush(classes[i][0], classes[i][1], pq, i);

        for(int i=0; i<extraStudents; i++) {
            int index = pq.top().second; pq.pop();
            heapPush(++classes[index][0], ++classes[index][1], pq, index);
        }

        double ans = 0.0;
        for(auto &i: classes) ans += (double) i[0] / i[1];
        return ans / n;
    }
};