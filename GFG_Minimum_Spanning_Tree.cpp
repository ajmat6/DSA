// ElogE (pq iterations and pop operation) + 2ElogE (inner adj list total traversal and push operation) is time and V + E is the space complexity:
class Solution {
	public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        int ansSum = 0;
        vector<int> vis (V, 0);
        vector<pair<int, int>> mst;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, -1}}); // weight, node, parent
        
        while(!pq.empty()) {
            int w = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();
            
            if(vis[node]) continue;
            
            ansSum += w;
            vis[node] = 1;
            if(parent != -1) mst.push_back({node, parent});
            
            for(auto i: adj[node]) {
                int adjNode = i[0];
                int weight = i[1];
                
                if(vis[adjNode] == 0) pq.push({weight, {adjNode, node}});
            }
        }
        
        return ansSum;
    }
};




// using kruskals algo: Disjoint set
// space is O(v + E) and time is V + E + ElogE + (E * 8 * @):
class DisjointSet {
    vector<int> rank, size, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    
    int ultimateParent(int node) {
        if(parent[node] == node) return node;
        else parent[node] = ultimateParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ultPU = ultimateParent(u);
        int ultPV = ultimateParent(v);
        
        if(ultPU == ultPV) return;
        
        if(rank[ultPU] > rank[ultPV]) parent[ultPV] = ultPU;
        else if(rank[ultPV] > rank[ultPU]) parent[ultPU] = ultPV;
        else {
            parent[ultPU] = ultPV;
            rank[ultPV]++;
        }
    }
    
    void unionBySize(int u, int v) {
        int ultPU = ultimateParent(u);
        int ultPV = ultimateParent(v);
        
        if(ultPU == ultPV) return;
        
        if(size[ultPV] < rank[ultPU]) {
            parent[ultPV] = ultPU;
            size[ultPU] += size[ultPV];
        }
        else {
            parent[ultPU] = ultPV;
            size[ultPV] += size[ultPU];
        }
    }
};

class Solution {
	public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        DisjointSet ds(V);
        
        vector<pair<int, pair<int, int>>> edges;
        // V + E time for below loops:
        for(int i=0; i<V; i++) {
            for(auto j: adj[i]) {
                int w = j[1];
                int u = j[0];
                int v = i;
                edges.push_back({w, {u, v}});
            }
        }
        
        // ElogE
        sort(edges.begin(), edges.end());
        int ans = 0;
        // E * 4 * @ * 2
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            
            
            int pU = ds.ultimateParent(u);
            int pV = ds.ultimateParent(v);
            if(pU == pV) continue;
            
            ans += edges[i].first;
            ds.unionByRank(u, v);
        }
        
        return ans;
    }
};
