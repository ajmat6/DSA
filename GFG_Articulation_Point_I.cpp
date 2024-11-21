class Solution {
  public:
    void dfs(int node, int parent, int& timer, vector<int>& vis, vector<int>& low, vector<int>& disc, vector<int>& mark, vector<int> adj[]) {
        vis[node] = 1;
        disc[node] = timer;
        low[node] = timer;
        
        int child = 0;
        for(auto i: adj[node]) {
            if(i == parent) continue;
            if(vis[i] == 0) {
                timer++;
                child++; // child is taken here because here there are self loops and 0 node can be a child of itself using self loops
                dfs(i, node, timer, vis, low, disc, mark, adj);
                low[node] = min(low[node], low[i]);
                if(low[i] >= disc[node] && parent != -1) mark[node] = 1;
            }
            else low[node] = min(low[node], disc[i]);
        }
        
        if(parent == -1 && child > 1) mark[node] = 1;
        return;
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int timer = 0;
        vector<int> vis(V);
        vector<int> low(V);
        vector<int> disc(V);
        vector<int> mark(V);
        
        dfs(0, -1, timer, vis, low, disc, mark, adj);
        
        vector<int> ans;
        for(int i=0; i<V; i++) {
            if(mark[i]) ans.push_back(i);
        }
        if(ans.size()) return ans;
        return {-1};
    }
};