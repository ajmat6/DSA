class Solution {
  private:
  void dfs(int node, stack<int>& st, vector<int>& vis, vector<vector<pair<int, int>>>& adjList) {
      vis[node] = 1;
      for(auto i: adjList[node]) {
          if(!vis[i.first]) dfs(i.first, st, vis, adjList);
      }
      st.push(node);
  }
  
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int, int>>> adjList (N);
        for(auto i: edges) adjList[i[0]].push_back({i[1], i[2]});
        
        stack<int> st;
        vector<int> vis (N);
        for(int i=0; i<N; i++) {
            if(!vis[i]) dfs(i, st, vis, adjList);
        }
        
        vector<int> dist (N, INT_MAX);
        dist[0] = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(dist[node] == INT_MAX) continue;
            for(auto i: adjList[node]) {
                if(dist[node] + i.second < dist[i.first]) dist[i.first] = dist[node] + i.second;
            }
        }
        
        for(auto &i: dist) {
            if(i == INT_MAX) i = -1;
        }
        return dist;
    }
};