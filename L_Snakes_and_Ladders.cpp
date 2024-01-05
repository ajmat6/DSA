class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int total = n * n;

        // Creating adjcancy list:
        unordered_map<int, int> adjList;
        int cell = 1;
        int turn = 0;

        for(int i=n-1; i>=0; i--)
        {
            if(turn == 0)
            {
                for(int j=0; j<n; j++)
                {
                    adjList[cell] = board[i][j];
                    cell++;
                }
                turn = 1;
            }

            else
            {
                for(int j=n-1; j>=0; j--)
                {
                    adjList[cell] = board[i][j];
                    cell++;
                }
                turn = 0;
            }
        }

        cout << "\n";

        queue<pair<int, int>> q;
        vector<int> vis (total + 1, 0);
        q.push({1, 0});
        vis[1] = 1;
        int ans = INT_MAX;

        while(!q.empty())
        {
            auto front = q.front();
            q.pop();

            int node = front.first;
            int count = front.second;

            // if we have reached last cell:
            if(node == total)
            {
                ans = min(ans, count);
                continue;
            }

            else
            {
                for(int i=node+1; i<=total && i<=node+6; i++)
                {
                    if(vis[i] == 1) continue;
                    else
                    {
                        if(adjList[i] == -1) q.push({i, count + 1});
                        else q.push({adjList[i], count + 1});
                        vis[i] = 1;
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};