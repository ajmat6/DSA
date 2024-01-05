class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adjList;
    int nodes;
    Graph(int n, vector<vector<int>>& edges) {
        nodes = n;
        // creating adjcancy list:
        for(auto i: edges)
        {
            int from = i[0];
            int to = i[1];
            int cost = i[2];

            adjList[from].push_back({to, cost});
        }
    }
    
    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        // using dijkstras algorithm:
        vector<int> dist (nodes, INT_MAX);
        dist[node1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node1});

        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int distance = top.first;
            int node = top.second;

            if(node == node2) return distance;

            for(auto i: adjList[node])
            {
                int destination = i.first;
                int cost = i.second;

                if(distance + cost < dist[destination])
                {
                    dist[destination] = distance + cost;
                    pq.push({distance + cost, destination});
                }
            }
        }

        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};