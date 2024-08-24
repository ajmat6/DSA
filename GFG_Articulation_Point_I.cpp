class Solution {
  public: 
    void solve(vector<int> adjList[], int& timer, int node, int parent, vector<int>& disc, vector<int>& low, vector<int>& vis, set<int>& st) {
        vis[node] = 1;
        disc[node] = low[node] = timer;
        
        int child = 0;
        for(auto i: adjList[node]) {
            int adjNode = i;
            if(adjNode == parent) continue;
            if(vis[adjNode] == 0) {
                timer++;
                solve(adjList, timer, i, node, disc, low, vis, st);
                low[node] = min(low[node],  low[adjNode]);
                if(low[adjNode] >= disc[node] && parent != -1) st.insert(node);
                child++;
            }
            else low[node] = min(low[node], disc[adjNode]);
        }
        
        if(parent == -1 && child > 1) st.insert(0);
        return;
    }
    
    vector<int> articulationPoints(int V, vector<int>adjList[]) {
        int timer = 0;
        vector<int> disc (V, -1);
        vector<int> low (V, -1);
        vector<int> vis (V, 0);
        set<int> st;
        solve(adjList, timer, 0, -1, disc, low, vis, st);
        vector<int> ans (st.begin(), st.end());
        if(ans.size() == 0) return {-1};
        return ans;
    }
};