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