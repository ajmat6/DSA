class Solution {
public:
    bool DFS(vector<vector<int>>& graph, vector<int>& color, int node, int col)
    {
        color[node] = col;

        for(auto i: graph[node])
        {
            // if adj node is not colored, color it:
            if(color[i] == -1)
            {
                bool ans = DFS(graph, color, i, col == 0 ? 1 : 0);
                if(!ans) return false;
            }

            // if already colored: check it should be different:
            else
            {
                if(color[node] == color[i]) return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // adjacency list is already given:
        int n = graph.size();
        vector<int> color (n, -1);

        for(int i=0; i<n; i++)
        {
            if(color[i] == -1)
            {
                bool ans = DFS(graph, color, i, 0);
                if(!ans) return false;
            }
        }

        return true;

        // Using BFS:

        // for(int i=0; i<n; i++)
        // {
        //     if(color[i] == -1)
        //     {
        //         queue<int> q;
        //         color[i] = 0; // coloring the i node with 0 color
        //         q.push(i);
        //         while(!q.empty())
        //         {
        //             int node = q.front();
        //             q.pop();

        //             for(auto i: graph[node])
        //             {
        //                 // if adj node is not colored, color it:
        //                 if(color[i] == -1)
        //                 {
        //                     if(color[node] == 0) color[i] = 1;
        //                     else color[i] = 0;
        //                     q.push(i);
        //                 }

        //                 // if already colored: check it should be different:
        //                 else
        //                 {
        //                     if(color[node] == color[i]) return false;
        //                 }
        //             }
        //         }
        //     }
        // }

        // return true;
    }
};