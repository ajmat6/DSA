class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int v, vector<int> adj[], int node, vector<int>& vis, stack<int>& st) {
	    vis[node] = 1;
	    for(auto i: adj[node]) {
	        if(!vis[i]) {
	            dfs(v, adj, i, vis, st);
	        }
	    }
	    
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // using dfs:
	    vector<int> ans;
	    stack<int> st;
	    vector<int> vis (V, 0);
	    for(int i=0; i<V; i++) {
	        if(!vis[i]) dfs(V, adj, 0, vis, st);
	    }
	    
	    while(!st.empty()) {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    
	    
	    
	    // using bfs: Kahn's algorithm:
	    vector<int> indegree(V, 0);
	    for(int i=0; i<V; i++) {
	        for(auto j: adj[i]) indegree[j]++;
	    }
	    
	    queue<int> q;
	    for(int i=0; i<V; i++) {
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    while(!q.empty()) {
	        int node = q.front();
	        ans.push_back(node);
	        
	        for(auto i: adj[node]) {
	            indegree[i]--;
	            if(indegree[i] == 0) q.push(i);
	        }
	    }
	    
	    return ans;
	}
};