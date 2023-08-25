class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // find the min distance to reach between evry city: Floyd Warshall:
        int row = edges.size();

        vector<vector<int>> cost (n, vector<int> (n, INT_MAX));

        // adj matrix creation:
        for(int i=0; i<row; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            cost[u][v] = w;
            cost[v][u] = w; // as it is undirected graph
        }

        for(int i=0; i<n; i++) cost[i][i] = 0; // self node distance

        // floyd warshall algo:
        for(int via=0; via<n; via++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(cost[i][via] == INT_MAX || cost[via][j] == INT_MAX) continue;

                    cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
                }
            }
        }

        // till here we have shortest distance to reach b/w any two cities:
        // we have to count for each city if cost does not exceed distanceThreashold:
        int city = -1; // assuming city -1 to be the city with min city to reach with atmost cost of distanceThreshold
        int minCityReachable = n + 1; // assuming max city reachable is n+1 initially

        // checking for each city that to how many cities it can reach with atmost distanceThreshold cost:
        for(int i=0; i<n; i++)
        {
            int countCity = 0;
            for(int j=0; j<n; j++)
            {
                if(cost[i][j] <= distanceThreshold)
                {
                    countCity++;
                }
            }

            // as we have to find city with min city it could reach:
            if(countCity <= minCityReachable)
            {
                minCityReachable = countCity;
                city = i;
            }
        }

        return city;
    }
};