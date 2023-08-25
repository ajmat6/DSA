class Solution {
public:
    bool DFS(vector<vector<int>>& graph, vector<bool>& isVisited, vector<bool>& DFSVisited, int node)
    {
        isVisited[node] = true;
        DFSVisited[node] = true;

        for(auto j: graph[node])
        {
            // condition for cycle detection:
            if(isVisited[j] && DFSVisited[j]) return true;

            if(!isVisited[j])
            {
                bool ans = DFS(graph, isVisited, DFSVisited, j);
                if(ans) return true; // cycle found;
            }
        }

        // mark node as false again in DFSVisited when all of its adjacent nodes are visited:
        DFSVisited[node] = false;

        return false; 
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> isVisited (n, false);
        vector<bool> DFSVisited (n, false);
        vector<int> ans;

        // traversing each node:
        for(int i=0; i<n; i++)
        {
            // if(!isVisited[i]) checking for each node even if it is visited or not
            // {
                bool result = DFS(graph, isVisited, DFSVisited, i);
                if(result == false) // means that node is not a part of the cycle
                {
                    ans.push_back(i);
                }
            // }
        }

        return ans;
    }
};