class Solution {
public:
    void DFS(vector<vector<int>>& rooms, vector<int>& vis, int index, unordered_map<int, list<int>> adjList)
    {
        vis[index] = 1;

        for(auto i: adjList[index])
        {
            if(!vis[i])
            {
                DFS(rooms, vis, i, adjList);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // create adjacancy list:
        unordered_map<int, list<int>> adjList;
        for(int i=0; i<rooms.size(); i++)
        {
            for(auto j: rooms[i])
            {
                adjList[i].push_back(j);
            }
        }

        // DFS: If we can visit all the rooms assuming them to be connected components, return true else false:
        // vector<int> vis (rooms.size(), 0);
        // DFS(rooms, vis, 0, adjList);

        // for(int i=0; i<vis.size(); i++)
        // {
        //     if(vis[i] == 0) return false;
        // }

        // return true;

        // BFS:
        queue<int> q;
        vector<int> vis (rooms.size(), 0);
        q.push(0);
        vis[0] = 1;

        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for(auto i: adjList[frontNode])
            {
                if(!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }

        for(int i=0; i<vis.size(); i++)
        {
            if(vis[i] == 0) return false;
        }

        return true;
    }
};