class Solution {
public:
    int solve(unordered_map<int, vector<int>>& adjList, int node, int& ans, vector<int>& vis) {
        vis[node] = 1;

        vector<int> arr;
        for(auto i: adjList[node]) {
            if(vis[i] == 0) arr.push_back(solve(adjList, i, ans, vis));
        }

        if(arr.size() == 0) {
            ans++;
            return 1;
        }

        int nodes = arr[0];
        bool poss = true; int total = arr[0];
        for(int i=1; i<arr.size(); i++) {
            if(poss && arr[i] != nodes) {
                poss = false;
            }
            total += arr[i];
        }

        if(poss) ans++;
        return total + 1;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjList;
        for(auto i: edges) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }

        int ans = 0;
        vector<int> vis (edges.size() + 1, 0);
        solve(adjList, 0, ans, vis);
        return ans;
    }
};