class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dis(V, 1e8);
        dis[S] = 0;
        for(int i=0; i<V-1; i++) {
            for(auto j: edges) {
                int u = j[0];
                int v = j[1];
                int w = j[2];
                
                if(dis[u] != 1e8 && dis[u] + w < dis[v]) dis[v] = dis[u] + w;
            }
        }
        
        // again do one more iteration for the negative cycles:
        for(auto j: edges) {
            int u = j[0];
            int v = j[1];
            int w = j[2];
                
            if(dis[u] != 1e8 && dis[u] + w < dis[v]) return {-1};
        }
        
        return dis; // no negative cycle found
    }
};