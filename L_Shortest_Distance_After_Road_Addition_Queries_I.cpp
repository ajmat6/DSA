class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
        for(int i=0; i<n-1; i++) adjList[i].push_back(i + 1);

        vector<int> ans;
        for(auto i: queries) {
            adjList[i[0]].push_back(i[1]);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> dist(n, INT_MAX);
            dist[0] = 0;
            pq.push({0, 0});

            while(!pq.empty()) {
                int node = pq.top().second;
                int distt = pq.top().first;
                pq.pop();

                for(auto j: adjList[node]) {
                    if(distt + 1 <= dist[j]) {
                        dist[j] = distt + 1;
                        pq.push({dist[j], j});
                    }
                }
            }

            ans.push_back(dist[n-1]);
        }

        return ans;
    }
};