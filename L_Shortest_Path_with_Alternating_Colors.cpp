class Solution {
public:
    void DFS(unordered_map<int, list<pair<int, int>>>& adjList, int node, int dist, int color, vector<int>& ans, set<pair<int, pair<int, int>>>& vis)
    {
        if(ans[node] == -1) ans[node] = dist;
        else ans[node] = min(ans[node], dist);

        vis.insert({node, {dist + 1, color}});

        for(auto i: adjList[node])
        {
            if(i.second != color && vis.find({i.first, {dist + 1, i.second}}) == vis.end())
            {
                // vis.insert({i.first, dist + 1, i.second});
                DFS(adjList, i.first, dist + 1, i.second, ans, vis);
            }
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // creating adjacancy list:
        unordered_map<int, list<pair<int, int>>> adjList;

        // red edges: track by 1:
        for(auto i: redEdges)
        {
            int u = i[0];
            int v = i[1];
            int c = 1; // red color by 1

            adjList[u].push_back({v, c}); // <from, <to, color>>
        }

        // blue edges: track by 2:
        for(auto i: blueEdges)
        {
            int u = i[0];
            int v = i[1];
            int c = 2; // blue color by 1

            adjList[u].push_back({v, c});
        }

        vector<int> ans (n, -1); // ans vector for distance
        set<pair<int, pair<int, int>>> vis;

        // DFS:
        // vis.insert({0, 0, -1});
        DFS(adjList, 0, 0, -1, ans, vis);
        return ans;


        // // BFS:
        // set<pair<int, int>> vis; // <node, color>, to track already visited nodes with a particular color
        // queue<vector<int>> q;
        // q.push({0, 0, -1}); // <node, dist, color>,  showing zero by -1 color, so that you can take any color after it
        // vis.insert({0, -1}); // marking 0 node with -1 color (initialisation) as visited

        // while(!q.empty())
        // {
        //     auto front = q.front();
        //     q.pop();

        //     int currNode = front[0];
        //     int currColor = front[2];
        //     int dist = front[1];

        //     // updating min distance to currNode:
        //     if(ans[currNode] == -1) ans[currNode] = dist;
        //     else ans[currNode] = min(ans[currNode], dist);

        //     // Traverse over child of currNode:
        //     for(auto i: adjList[currNode])
        //     {
        //         // if adj edge color is diff from present one and adjNode and its color is not already visited:
        //         if(i.second != currColor && vis.find({i.first, i.second}) == vis.end())
        //         {
        //             q.push({i.first, dist + 1, i.second}); // incresing distance by 1 for adj node
        //             vis.insert({i.first, i.second});
        //         }
        //     }
        // }

        // return ans;
    }
};