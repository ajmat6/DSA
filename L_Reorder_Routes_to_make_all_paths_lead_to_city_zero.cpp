class Solution {
public:
    int ans = 0;
    void solve(vector<vector<int>>& conn, unordered_map<int, list<pair<int, int>>>& adjList, int node, vector<int>& vis)
    {
        vis[node] = 1;
        for(auto i: adjList[node])
        {
            int to = i.first;
            int from = i.second; // actual dicrection of the edge in connections vector. To track from which node to which. so here from indicates that 'from'

            if(vis[to] == 0)
            {
                if(node == from) ans++; // if edge is from 0 -> 1 we want to reverse it (think about this)
                solve(conn, adjList, to, vis);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& conn) {
        // Creates adjacancy list:
        unordered_map<int, list<pair<int, int>>> adjList;
        for(int i=0; i<conn.size(); i++)
        {
            adjList[conn[i][0]].push_back({conn[i][1], conn[i][0]});
            adjList[conn[i][1]].push_back({conn[i][0], conn[i][0]});
        }

        // vector<int> vis (n, 0);
        // solve(conn, adjList, 0, vis);
        // return ans;

        int ans = 0;
        queue<int> q;
        q.push(0);
        vector<int> vis (n, 0);

        while(!q.empty())
        {
            int node = q.front(); q.pop();
            vis[node] = 1;

            for(auto i: adjList[node])
            {
                int to = i.first;
                int from = i.second;

                if(vis[to] == 0)
                {
                    if(node == from) ans++;
                    q.push(to);
                }
            }
        }
        return ans;
    }
};