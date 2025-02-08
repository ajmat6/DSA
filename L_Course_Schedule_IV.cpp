class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<int> indegree (numCourses, 0);
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, unordered_set<int>> preReq;

        for(int i=0; i<pre.size(); i++) {
            indegree[pre[i][1]]++;
            adjList[pre[i][0]].push_back(pre[i][1]);
            preReq[pre[i][1]].insert(pre[i][0]);
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front(); q.pop();
            for(auto i: adjList[node]) {
                // preReq[i].insert(node); // already done during adjList formation
                preReq[i].insert(preReq[node].begin(), preReq[node].end());
                if(--indegree[i] == 0) q.push(i);
            }
        }

        vector<bool> ans;
        for(int i=0; i<queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            ans.push_back(preReq[b].count(a));
        }
        return ans;
    }
};