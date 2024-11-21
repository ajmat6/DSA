class Solution {
  public:
    bool checkColor(int node, int currColor, unordered_map<int, vector<int>>& adjList, vector<int>& color) {
        for(auto i: adjList[node]) {
            if(color[i] == currColor) return false;
        }
        return true;
    }
    
    bool dfs(unordered_map<int, vector<int>>& adjList, vector<int>& color, int node, int& m) {
        if(node == color.size()) return true;
        
        for(int i=1; i<=m; i++) {
            if(checkColor(node, i, adjList, color)) {
                color[node] = i;
                if(dfs(adjList, color, node + 1, m)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(int n, vector<pair<int, int>>& edges, int m) {
        unordered_map<int, vector<int>> adjList;
        for(auto i: edges) {
            adjList[i.first].push_back(i.second);
            adjList[i.second].push_back(i.first);
        }
        
        vector<int> color (n, 0);
        return dfs(adjList, color, 0, m);
    }
};