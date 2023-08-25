// TC = O(V * E) and SC = O(V) for distance array
class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // distance array:
        vector<int> dist (V, 1e8);
        dist[S] = 0;
        
        // iteration over each V-1 times:
        for(int i=0; i<V-1; i++)
        {
            for(auto i: edges)
            {
                int u = i[0];
                int v = i[1];
                int distance = i[2];
                
                if(dist[u] + distance < dist[v])
                {
                    dist[v] = dist[u] + distance;
                }
            }
        }
        
        // one more iteration for negative cycle detection:
        for(auto i: edges)
        {
            int u = i[0];
            int v = i[1];
            int distance = i[2];
            
            if(dist[u] + distance < dist[v])
            {
                return {-1};
            }
        }
        
        return dist;
    }
};
