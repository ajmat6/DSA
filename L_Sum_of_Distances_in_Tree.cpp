class Solution {
public:
    void dfs(int node, int parent, vector<int>& ans, vector<int>& count, unordered_map<int, vector<int>>& adjList) {
        for(auto i: adjList[node]) {
            int child = i;
            if(child != parent) {
                dfs(i, node, ans, count, adjList);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }

    void dfs2(int n, int node, int parent, vector<int>& ans, vector<int>& count, unordered_map<int, vector<int>>& adjList)  {
        if(parent != -1) ans[node] = ans[parent] - count[node] + (n - count[node]);
        for(auto i: adjList[node]) {
            int child = i;
            if(child != parent) {
                dfs2(n, child, node, ans, count, adjList);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // applying floyd wardshall: Gives TLE:
        // vector<vector<int>> adjMatrix (n, vector<int> (n, 1e9));
        // for(int i=0; i<n; i++) adjMatrix[i][i] = 0;
        // for(auto i: edges) {
        //     int node1 = i[0];
        //     int node2 = i[1];
        //     adjMatrix[node1][node2] = 1;
        //     adjMatrix[node2][node1] = 1;
        // }

        // for(int via=0; via<n; via++) {
        //     for(int i=0; i<n; i++) {
        //         for(int j=0; j<n; j++) {
        //             adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);
        //         }
        //     }
        // }

        // vector<int> ans;
        // for(int i=0; i<n; i++) {
        //     int sum = 0;
        //     for(int j=0; j<n; j++) {
        //         sum += adjMatrix[i][j];
        //     }

        //     ans.push_back(sum);
        // }

        // return ans;


        unordered_map<int, vector<int>> adjList;
        for(auto i: edges) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }

        vector<int> ans (n);
        vector<int> count (n, 1);
        dfs(0, -1, ans, count, adjList);
        dfs2(n, 0, -1, ans, count, adjList);
        return ans;
    }
};