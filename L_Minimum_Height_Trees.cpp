class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        
        // creation of adjacancy list:
        unordered_map<int, list<int>> adjList;
        vector<int> indegree (n, 0); // indegree vector:

        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);

            indegree[u]++;
            indegree[v]++;
        }

        queue<int> q;
        vector<int> ans; // vector to track middle nodes of longest path:

        // finding all 1 indegree nodes:
        for(int i=0; i<indegree.size(); i++)
        {
            if(indegree[i] == 1) q.push(i);
        }

        while(!q.empty())
        {
            int size = q.size();
            ans.clear(); // for next iteration

            for(int i=0; i<size; i++)
            {
                int front = q.front();
                q.pop();
                ans.push_back(front);

                for(auto x: adjList[front])
                {
                    indegree[x]--;
                    if(indegree[x] == 1) q.push(x);
                }
            }
        }

        return ans;
    }
};