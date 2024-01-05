class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree (n+1, 0);
        for(auto i: trust)
        {
            int u = i[0];
            int v = i[1];

            adjList[u].push_back(v);
            indegree[v]++; // count indegree of each person
        }

        for(int i=1; i<=n; i++)
        {
            // if a person is trusted by all the persson and he do not trust anyone -> Judge found
            if(indegree[i] == n - 1 && adjList[i].size() == 0) return i;
        }

        return -1;
    }
};