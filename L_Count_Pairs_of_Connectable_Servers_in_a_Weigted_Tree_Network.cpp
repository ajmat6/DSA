class Solution {
public:
    // TC is O(n^2) and SC is O(N)
    int dfs(unordered_map<int, vector<pair<int, int>>>& adjList, int node, int parent, int total, int ss) {
        int ans = total % ss == 0 ? 1 : 0;
        for(auto i: adjList[node]) {
            if(i.first != parent) ans += dfs(adjList, i.first, node, total + i.second, ss);
        }

        return ans;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int ss) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        int maxi = INT_MIN;
        for(auto i: edges) {
            adjList[i[0]].push_back({i[1], i[2]});
            adjList[i[1]].push_back({i[0], i[2]});
            maxi = max(maxi, max(i[0], i[1]));
        }
        
        vector<int> ans (maxi + 1);
        for(int i=0; i<=maxi; i++) {
            // if atleast two nodes are connected to a node, then it can be server node b/w them
            if(adjList[i].size() > 1) {
                // for each subtree for a node, checking the conditions using dfs:
                vector<int> temp;
                int total = 0;
                int totalNodes = 0;
                for(auto j: adjList[i]) { // this will give O(n) TC as at worst all the nodes are visited once during dfs
                    int res = dfs(adjList, j.first, i, j.second, ss);
                    total += totalNodes * res; 
                    totalNodes += res;
                }

                ans[i] = total;
            }
        }

        return ans;
    }
};