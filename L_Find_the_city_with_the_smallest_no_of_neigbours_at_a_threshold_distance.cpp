class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        // // Creation of the adjcancy list:
        // unordered_map<int, vector<pair<int, int>>> adjList;
        // for(auto i: edges) {
        //     adjList[i[0]].push_back({i[1], i[2]});
        //     adjList[i[1]].push_back({i[0], i[2]});
        // }

        // // using dijkstra algo:
        // int leastCity = INT_MAX;
        // int ans = -1;
        // for(int i=0; i<n; i++) {
        //     vector<int> dist (n, INT_MAX);
        //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //     pq.push({0, i});

        //     while(!pq.empty()) {
        //         int distt = pq.top().first;
        //         int node = pq.top().second; pq.pop();
        //         // if(dist[node] < distt) continue;

        //         if(distt < dist[node]) {
        //             for(auto j: adjList[node]) {
        //                 int newNode = j.first;
        //                 int weight = j.second;
        //                 if(distt + weight < dist[newNode]) {
        //                     dist[newNode] = distt + weight;
        //                     pq.push({dist[newNode], newNode});
        //                 }
        //             }
        //         }
        //     }

        //     int count = 0;
        //     for(int j=0; j<n; j++) {
        //         if(j != i && dist[j] <= dt) count++;
        //     }
        //     if(count <= leastCity) {
        //         leastCity = count;
        //         ans = i;
        //     }
        // }

        // return ans;




        // using floyd warshall algo:
        vector<vector<int>> adjMatrix (n, vector<int> (n, 1e9));
        for(int j=0; j<n; j++) adjMatrix[i][i] = 0;
        for(auto i: edges) {
            adjMatrix[i[0]][i[1]] = i[2];
            adjMatrix[i[1]][i[0]] = i[2];
        }

        // floyd warshall algo:
        for(int via=0; via<n; via++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);
            }
        }

        int ans = -1; int leastCity = INT_MAX;
        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                if(i != j && adjMatrix[i][j] <= dt) count++;
            }

            if(count <= leastCity) {
                leastCity = count;
                ans = i;
            }
        }

        return ans;
    }
};