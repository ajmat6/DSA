class Solution {
public:
    // dsu:
    class DisjointSet {
        vector<int> parent, size;
        public:
        DisjointSet(int n) {
            parent.resize (n + 1);
            size.resize(n + 1);

            for(int i=0; i<parent.size(); i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int ultParent(int n) {
            if(parent[n] == n) return n;
            else return parent[n] = ultParent(parent[n]);
        }

        void unionn(int u, int v) {
            int ultPrtU = ultParent(u);
            int ultPrtV = ultParent(v);

            if(ultPrtU == ultPrtV) return;

            int sizeU = size[ultPrtU];
            int sizeV = size[ultPrtV];

            if(sizeU >= sizeV) {
                parent[ultPrtV] = ultPrtU;
                size[ultPrtU] += size[ultPrtV];
            }

            else {
                parent[ultPrtU] = ultPrtV;
                size[ultPrtV] += size[ultPrtU];
            }
        }
    };

    // dfs:
    bool solve(unordered_map<int, vector<int>>& adjList, int curr, int destination, vector<int>& vis) {
        if(curr == destination) return true;
        if(!vis[curr]) {
            vis[curr] = 1;
            for(auto i: adjList[curr]) {
                if(vis[i] == 0 && solve(adjList, i, destination, vis)) return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // create adjacancy list:
        unordered_map<int, vector<int>> adjList;
        for(auto i: edges) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }

        // using dfs:
        // vector<int> vis (n + 1, 0);
        // return solve(adjList, source, destination, vis);


        // using bfs
        // if(source == destination) return true;
        // queue<int> q;
        // vector<int> vis (n + 1);
        // q.push(source);
        // vis[source] = 1;

        // while(!q.empty()) {
        //     int node = q.front(); q.pop();
        //     for(auto i: adjList[node]) {
        //         if(i == destination) return true;
        //         else if(!vis[i]) {
        //             vis[i] = 1;
        //             q.push(i);
        //         }
        //     }
        // }
        // return false;


        // using dsu:
        DisjointSet ds (n + 1);
        for(auto i:  edges) ds.unionn(i[0], i[1]);
        if(ds.ultParent(source) == ds.ultParent(destination)) return true;
        return false;

    }
};