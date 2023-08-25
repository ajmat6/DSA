// TC = O(ElogE) and SC = O(E+V)
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        // second step: make a pq for storing node with min weight {{weight, node}, parent}
        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> q;
        
        // third step: creating visited, key and parent vectors:
        vector<bool> vis (V);
        vector<int> key (V);
        vector<int> parent (V);
        
        // initializing key, vis and parent vector:
        for(int i=0; i<V; i++)
        {
            parent[i] = -1;
            key[i] = INT_MAX;
            vis[i] = false;
        }
        
        key[0] = 0;
        parent[0] = -1;
        
        // put 0 node into the pq:
        q.push({{0, 0}, -1}); // parent of 0 is -1
        
        while(!q.empty())
        {
            auto top = q.top();
            q.pop();
            
            int node = top.first.second;
            int weight = top.first.first;
            int parentNode = top.second;
            
            // checking if node is already visited:
            if(vis[node]) continue;
            
            // if not visited, mark it visited: here you are adding it to mst
            vis[node] = true;
            
            // checking for adjacent node:
            for(auto i: adj[node])
            {
                int adjNode = i[0];
                int weight = i[1];
                
                if(!vis[adjNode] && weight < key[adjNode])
                {
                    q.push({{weight, adjNode}, node});
                    
                    parent[adjNode] = node;
                    key[adjNode] = weight;
                }
            }
        }
        
        // creaing ans:
        int ans = 0;
        for(int i=1; i<parent.size(); i++)
        {
            ans += key[i];
        }
        
        return ans;
    }
};