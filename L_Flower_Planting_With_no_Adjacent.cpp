class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> color (n, 0);
        vector<int> vis (n, 0);

        // Creating adj list:
        unordered_map<int, list<int>> adjList;
        for(auto i: paths)
        {
            int u = i[0];
            int v = i[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<vector<int>> alreadyColored (n, vector<int> (4, 0));
        queue<int> q;
        for(int i=1; i<=n; i++)
        {
            if(!vis[i-1])
            {
                q.push(i);
                vis[i-1] = 1;

                while(!q.empty())
                {
                    int front = q.front();
                    q.pop();

                    // checking which color can be given to front node
                    int col = 1;
                    for(; col<=4; col++)
                    {
                        if(alreadyColored[front-1][col-1] == 0) break; // color that could be colored on current node is found
                    }

                    alreadyColored[front-1][col-1] = 1; // marking that color so that its adjacnet nodes cannot use this color
                    color[front - 1] = col;

                    // traverse over adjNodes and look for colors:
                    for(auto j: adjList[front])
                    {
                        if(!vis[j-1])
                        {
                            vis[j-1] = 1;
                            q.push(j);
                        }

                        // marking used at color used by front node so that its adj node dont use it:
                        alreadyColored[j-1][col-1] = 1;
                    }
                }
            }
        }

        return color;
    }
};