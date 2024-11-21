// SC is ((V + 2E) + V + V + V + E + V) or(adjList, disc, low, vis, ans, recur stack space):
// TC is V + 2E
class Solution {
public:
    void dfs(int node, int parent, unordered_map<int, vector<int>>& adjList, int& timer, vector<int>& disc, vector<int>& low, vector<int>& vis, vector<vector<int>>& ans) {
        disc[node] = timer;
        low[node] = timer;
        vis[node] = 1;

        for(auto i: adjList[node]) {
            if(i == parent) continue;
            if(!vis[i]) {
                timer++;
                dfs(i, node, adjList, timer, disc, low, vis, ans);
            }
            low[node] = min(low[node], low[i]);
            if(low[i] > disc[node]) ans.push_back({node, i});
        }
        return;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        unordered_map<int, vector<int>> adjList;
        for(auto i: conn) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }

        int timer = 0;
        vector<int> low(n);
        vector<int> vis(n);
        vector<int> disc(n);
        vector<vector<int>> ans;

        dfs(0, -1, adjList, timer, disc, low, vis, ans);
        return ans;
    }
};