class Solution
{
	public:
	// function to store the nodes in stack acc to their findishing time
	void DFS(vector<vector<int>>& adj, vector<int>& vis, int node, stack<int>& st)
	{
	   vis[node] = 1;
	   for(auto i: adj[node])
	   {
	       if(!vis[i])
	       {
	           DFS(adj, vis, i, st);
	       }
	   }
	   
	   st.push(node);
	}
	
	// function to find the scc by dfs
	void dfs(int node, vector<vector<int>>& adj, vector<int>& vis)
	{
	   vis[node] = 1;
	   for(auto i: adj[node])
	   {
	       if(!vis[i])
	       {
	           dfs(i, adj, vis);
	       }
	   }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis (V, 0);
        stack<int> st;
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                DFS(adj, vis, i, st);
            }
        }
        
        // reverse the edges in the graph:
        vector<vector<int>> rev (V);
        for(int i=0; i<V; i++)
        {
            vis[i] = 0; // again marking all nodes as unvisited to use them in dfs down:
            for(auto j: adj[i])
            {
                rev[j].push_back(i);
            }
        }
        
        // do dfs according to the finishing time:
        int scc = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            if(!vis[node])
            {
                scc++;
                dfs(node, rev, vis);
            }
        }
        
        return scc;
    }
};
