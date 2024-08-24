class Solution {
public:
    void solve(int n, unordered_map<int, vector<int>>& adjList, int& timer, int node, int parent, vector<vector<int>>& ans, vector<int>& disc, vector<int>& low, vector<int>& vis) {
        vis[node] = 1;
        disc[node] = timer;
        low[node] = timer;

        for(auto i: adjList[node]) {
            if(vis[i] == 0) {
                timer++;
                solve(n, adjList, timer, i, node, ans, disc, low, vis);
            }
            if(i != parent && low[i] < low[node]) low[node] = low[i];
            if(low[i] > disc[node]) {
                ans.push_back({i, node});
            }
        }

        return;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> adjList;
        for(auto i: connections) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }

        vector<int> disc (n, -1);
        vector<int> low (n, -1);
        vector<int> vis (n, 0);

        int timer = 0;
        vector<vector<int>> ans;
        solve(n, adjList, timer, 0, -1, ans, disc, low, vis);
        return ans;
    }
223waqqq1