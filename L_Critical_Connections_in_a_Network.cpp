// Bridges in a Graph:

class Solution {
public:
    int timer = 1;
    void DFS(int node, int parent, unordered_map<int, list<int>>& adjList, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<vector<int>>& ans)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto i: adjList[node])
        {
            if(i == parent) continue;
            if(vis[i] == 0)
            {
                DFS(i, node, adjList, vis, tin, low, ans);
                low[node] = min(low[node], low[i]);

                // check if its adj nodes lowest time is greater than its time of insertion: Bridge present:
                if(low[i] > tin[node])
                {
                    ans.push_back({node, i});
                }
            }

            // if adj node is already vis, check for updated lowest time: when 2 will check for its adj node 0 which is not its parent(1 is parent of 2) and its lowest time will get updated:
            else
            {
                low[node] = min(low[node], low[i]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // creating adjacancy list:
        unordered_map<int, list<int>> adjList;
        for(auto i: connections)
        {
            int u = i[0];
            int v = i[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> vis (n, 0);
        vector<int> tin (n, 0);
        vector<int> low (n, 0);
        vector<vector<int>> ans;
        DFS(0, -1, adjList, vis, tin, low, ans);
        return ans;
    }
};