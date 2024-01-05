class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;

        // create adjacancy list:
        unordered_map<int, vector<int>> adjList;
        for(int i=0; i<routes.size(); i++)
        {
            for(auto j: routes[i])
            {
                adjList[j].push_back(i);
            }
        }

        // doing bfs:
        queue<int> q; // <routeNo>
        unordered_set<int> vis; // for already vis routes
        // inserting all routes that contain source: multisource bfs
        for(auto i: adjList[source])
        {
            q.push(i);
            vis.insert(i);
        }

        int busCount = 1;
        while(!q.empty())
        {
            int size = q.size();

            // check on this route if target is there or not:
            for(int i=0; i<size; i++)
            {
                int route = q.front();
                q.pop();

                for(int j=0; j<routes[route].size(); j++)
                {
                    int node = routes[route][j];
                    if(node == target) return busCount;

                    for(auto k: adjList[node])
                    {
                        if(vis.find(k) == vis.end())
                        {
                            q.push(k);
                            vis.insert(k);
                        }
                    }
                }
            }

            busCount++; 
        }

        return -1;
    }
};