class Solution {
public:
    void DFS(vector<vector<int>>& isConnected, unordered_map<int, bool>& isVisited, int node)
    {
        // marking true for curr node DFS call:
        isVisited[node] = true;

        // Checking for the adjacent elements of curr node:
        for(int j=0; j<isConnected[node].size(); j++)
        {
            if(isConnected[node][j] == 1 && !isVisited[j])
            {
                DFS(isConnected, isVisited, j);
            }
        }
    }

    void BFS(vector<vector<int>>& isConnected, unordered_map<int, bool>& isVisited, int node)
    {
        queue<int> q;
        q.push(node);
        isVisited[node] = true;

        // traverse over queue till it is not empty:
        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for(int j=0; j<isConnected[frontNode].size(); j++)
            {
                if(isConnected[frontNode][j] == 1 && !isVisited[j])
                {
                    isVisited[j] = true;
                    q.push(j);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // unordered map for node visit track:
        unordered_map<int, bool> isVisited;

        // ans variable for no of provinces:
        int ans = 0;

        // // loop for the track of every disconnected component: Using DFS
        // for(int i=0; i<isConnected.size(); i++)
        // {
        //     if(!isVisited[i])
        //     {
        //         ans++;
        //         DFS(isConnected, isVisited, i);
        //     }
        // }

        // loop for the track of every disconnected component: Using BFS
        for(int i=0; i<isConnected.size(); i++)
        {
            if(!isVisited[i])
            {
                ans++;
                BFS(isConnected, isVisited, i);
            }
        }

        return ans;
    }
};