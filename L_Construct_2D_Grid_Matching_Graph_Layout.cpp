class Solution {
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<int> adjList[n];
        for(auto &i: edges) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }

        int minNode = 0;
        int minDegree = n;
        for(int i=0; i<n; i++) {
            if(adjList[i].size() < minDegree) {
                minDegree = adjList[i].size();
                minNode = i;
            }
        }

        // find node and the shortest path to the node with same minDegree ans minNode:
        queue<int> q;
        vector<int> parent (n, -1);
        q.push(minNode);
        parent[minNode] = -2;

        int secondNode = -1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            bool found = false;
            for(auto &i: adjList[node]) {
                if(parent[i] == -1) {
                    parent[i] = node;
                    if(adjList[i].size() == minDegree) {
                        secondNode = i;
                        found = true;
                        break;
                    } 
                    else q.push(i);
                }
            }
            if(found) break;
        }

        // finding first row from the parent array:
        int count = n;
        vector<int> temp;
        vector<int> vis (n, 0);
        vector<vector<int>> ans;
        while(secondNode != -2) {
            vis[secondNode] = 1;
            count -= 1;
            temp.push_back(secondNode);
            secondNode = parent[secondNode];
        }

        ans.push_back(temp);
        while(count != 0) {
            temp.clear();
            for(auto &i: ans.back()) {
                for(auto &j: adjList[i]) {
                    if(!vis[j]) {
                        vis[j] = 1;
                        temp.push_back(j);
                        count -= 1;
                        break;
                    }
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};