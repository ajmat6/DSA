class Solution {
public:
    void solve(int node, int curr, unordered_map<int, vector<int>>& adjList, vector<vector<int>>& ans, vector<int>& vis) {
        vis[curr] = 1;
        for(auto i: adjList[curr]) {
            if(!vis[i]) {
                ans[node].push_back(i);
                solve(node, i, adjList, ans, vis);
            }
        }
        return;
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // unordered_map<int, vector<int>> adjList;
        // for(auto i: edges) adjList[i[1]].push_back(i[0]);

        // vector<vector<int>> ans (n);
        // for(int i=0; i<n; i++) {
        //     vector<int> vis (n);
        //     solve(i, i, adjList, ans, vis);
        // }
        // for(auto &i: ans) sort(i.begin(), i.end());
        // return ans;



        unordered_map<int, vector<int>> adjList;
        vector<int> indegree (n, 0);
        for(auto i: edges) {
            adjList[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        } 

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<vector<int>> ans (n);
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto i: adjList[node]) {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
                
                ans[i].push_back(node);
                for(auto j: ans[node]) {
                    ans[i].push_back(j);
                }

                sort(ans[i].begin(), ans[i].end()); int curr = 1;
                for(int j=1; j<ans[i].size(); j++) {
                    if(ans[i][j] != ans[i][j-1]) ans[i][curr++] = ans[i][j];
                }

                ans[i].resize(curr);
            }
        }

        // for(auto i: mp) {
        //     int node = i.first;
        //     vector<int> temp;
        //     for(auto j: i.second) ans[node].push_back(j);
        // }
        return ans;
    }
};