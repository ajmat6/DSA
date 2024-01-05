class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        // if there is only one node in the graph:
        if(n == 1) return 0;

        int finalState = (1 << n) - 1; // for n = 3 -> 1 << n will be eight. So 8 - 1 = 7 which has all there bits as 1 which we want as final state that all thre node as visited:

        queue<pair<int, pair<int, int>>> q; // <node, <dist, visited mask>>

        // you have to maintain set to keep track of the already visited form of binary representation:
        set<pair<int, int>> vis; // <node, pattern> to keep track that a node with given vis pattern is already vis or not

        // as shortest path can be from any node in the graph, we have to push all the nodes in the graph:
        for(int i=0; i<n; i++)
        {
            int maskOrVis = 1 << i;
            q.push({i, {0, maskOrVis}});
            vis.insert({i, maskOrVis});
        }

        int ans = INT_MAX;
        while(!q.empty())
        {
            int node = q.front().first;
            int dist = q.front().second.first;
            int mask = q.front().second.second;
            q.pop();

            for(auto i: graph[node])
            {
                // if previous mask was 001 meaning 0th node is visited then for the adj nodes, we have to change that mask by:
                int newMask = mask | (1 << i); 
                
                // check if after making new mask all the nodes are vis or not -> matching it with finalState:
                if(newMask == finalState)
                {
                    // ans = min(ans, dist + 1);
                    // first time that will make newMask equal to final state is smallest distance:
                    return dist + 1;
                }

                // if the current node with newMask pattern is already present in the set, then dont push it into the set:
                else if(vis.find({i, newMask}) != vis.end())
                {
                    continue;
                }

                // if newMask is not final state and also not already visited pattern, insert it into the queue:
                else
                {
                    q.push({i, {dist + 1, newMask}});
                    vis.insert({i, newMask});
                }
            }
        }

        return ans; // finding min ans will also work but it will do unnecessary iteration
    }
};