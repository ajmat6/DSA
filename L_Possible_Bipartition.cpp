class Solution {
public:
    bool DFS(unordered_map<int, list<int>>& adjList, int node, vector<int>& vis)
    {
        for(auto i: adjList[node])
        {
            if(vis[i] == -1)
            {
                if(vis[node] == 1) vis[i] = 0;
                else vis[i] = 1;

                bool result = DFS(adjList, i, vis);
                if(!result) return false;
            }

            else
            {
                if(vis[i] == vis[node]) return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // Create adjacancy list:
        unordered_map<int, list<int>> adjList;
        for(auto i: dislikes)
        {
            int u = i[0];
            int v = i[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> vis (n+1, -1);

        // DFS:
        for(int i=1; i<=n; i++)
        {
            if(vis[i] == -1)
            {
                vis[i] = 1;
                bool temp = DFS(adjList, i, vis);
                if(!temp) return false;
            }
        }

        return true;

        // BFS:
        // queue<int> q;
        // for(int i=1; i<=n; i++)
        // {
        //     if(vis[i] == -1)
        //     {
        //         q.push(i);
        //         vis[i] = 1;

        //         while(!q.empty())
        //         {
        //             int front = q.front();
        //             q.pop();

        //             // check for the adjacent node of front element:
        //             for(auto j: adjList[front])
        //             {
        //                 if(vis[j] == -1)
        //                 {
        //                     if(vis[front] == 1) vis[j] = 0;
        //                     else vis[j] = 1;

        //                     q.push(j);
        //                 }

        //                 else
        //                 {
        //                     if(vis[j] == vis[front]) return false;
        //                 }
        //             }
        //         }

        //     }
        // }

        // return true;
    }
}; 