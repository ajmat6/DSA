class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        // Creating adjacancy list:
        unordered_map<int, list<pair<int, int>>> adjList;
        for(auto i: edges)
        {
            int u = i[0];
            int v = i[1];
            int div = i[2];

            adjList[u].push_back({v, div});
            adjList[v].push_back({u, div});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist (n, INT_MAX);

        pq.push({0, 0});
        dist[0] = 0;

        // doing normal dijksta algo process initially:
        while(!pq.empty())
        {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto i: adjList[node])
            {
                int nextNode = i.first;
                int noOfDiv = i.second;

                if(dist[nextNode] > distance + noOfDiv + 1)
                {
                    dist[nextNode] = distance + noOfDiv + 1;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        // Now cheking for the subdivisions:
        int ans = 0;
        for(auto i: edges)
        {
            int src = i[0];
            int destination = i[1];
            int div = i[2];

            int fromSource = max(0, maxMoves - dist[src]);
            int fromDestination = max(0, maxMoves - dist[destination]);
            int total = min(div, fromSource + fromDestination);
            ans += total;
        }

        for(int i=0; i<n; i++)
        {
            if(dist[i] <= maxMoves) ans++;
        }

        return ans;
    }
};