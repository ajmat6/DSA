bool dfs(int node, vector<int>& vis, vector<int>& pathVis, unordered_map<int, vector<int>>& adjList) {
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto i: adjList[node]) {
        if(vis[i] && pathVis[i]) return true;
        if(!vis[i] && dfs(i, vis, pathVis, adjList)) return true;
    }

    pathVis[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, vector<int>> adjList;
    for(auto i: edges) {
        adjList[i.first].push_back(i.second);
    }

    vector<int> vis(n + 1, 0);
    vector<int> pathVis(n + 1, 0);

    for(int i=1; i<=n; i++) {
        if(!vis[i] && dfs(i, vis, pathVis, adjList)) return true;
    }
    return false;
}