class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adjList[N];
        for(auto i: edges) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        
        vector<int> dist (N, -1);
        dist[src] = 0;
        
        queue<int> q;
        q.push(src);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto i: adjList[node]) {
                if(dist[i] == -1) {
                    dist[i] = 1 + dist[node];
                    q.push(i);
                }
            }
        }
        
        return dist;
    }
};