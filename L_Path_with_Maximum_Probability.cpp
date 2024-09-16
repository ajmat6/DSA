class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> adjList;
        for(int i=0; i<edges.size(); i++) {
            adjList[edges[i][0]].push_back({edges[i][1], succ[i]});
            adjList[edges[i][1]].push_back({edges[i][0], succ[i]});
        }

        vector<int> vis (n);
        vector<double> dist (n, 0.0);
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});

        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            vis[node.second] = 1;
            for(auto i: adjList[node.second]) {
                if(!vis[i.first] && dist[i.first] < node.first * i.second) {
                    dist[i.first] = node.first * i.second;
                    pq.push({dist[i.first], i.first});
                }
            }
        }

        return dist[end];
    }
};