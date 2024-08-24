class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> freq(n);
        for(auto i: roads) {
            freq[i[0]]++;
            freq[i[1]]++;
        }

        priority_queue<int> pq;
        for(auto i: freq) pq.push(i);

        long long ans = 0;
        while(!pq.empty()) {
            ans += n * 1LL * pq.top(); pq.pop();
            n -= 1;
        }
        return ans;
    }
};