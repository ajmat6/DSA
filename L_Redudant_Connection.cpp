vector<int> ans; // to store ans:

// Disjoint sets defination:
class DisjointSet
{
    public:
    vector<int> size;
    vector<int> parent;

    DisjointSet(int n)
    {
        size.resize(n+1);
        parent.resize(n+1);

        for(int i=0; i<parent.size(); i++)
        {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int ultimateParent(int n)
    {
        if(parent[n] == n) return n;
        else return parent[n] = ultimateParent(parent[n]);
    }

    void unionBySize(int u, int v)
    {
        int uprtU = ultimateParent(u);
        int uprtV = ultimateParent(v);

        if(uprtU == uprtV)
        {
            if(ans.size() > 0)
            {
                ans.clear();
                ans.push_back(u);
                ans.push_back(v);
            }
            else
            {
                ans.push_back(u);
                ans.push_back(v); 
            }
        }

        if(size[uprtU] > size[uprtV])
        {
            size[uprtU] += size[uprtV];
            parent[uprtV] = uprtU;
        }

        else
        {
            size[uprtV] += size[uprtU];
            parent[uprtU] = uprtV; 
        }
    }
};

class Solution {
public:
    bool DFS(vector<vector<int>>& adj, int node, vector<int>& vis, int parent)
    {
        if(vis[node]) return true; // if already visited, cycle found
        vis[node] = true; // visiting the node:

        for(auto i: adj[node]) // checking for its adj nodes:
        {
            if(i != parent && DFS(adj, i, vis, node)) return true;
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // DisjointSet ds(n);

        // // making union of the edges:
        // for(auto i: edges)
        // {
        //     int u = i[0];
        //     int v = i[1];

        //     // when ultimate parent of two nodes is same then they are already connected and that edge can be considered to be the edge that has to be removed:
        //     ds.unionBySize(u, v);
        // }

        // return ans;


        // Using DFS:
        vector<int> vis (n+1);
        vector<vector<int>> adj (n+1);

        for(auto i: edges)
        {
            fill(begin(vis), end(vis), false); // as on each edge addition, we will traverse again
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);

            // if cycle if found return current node edge i:
            if(DFS(adj, i[0], vis, -1)) return i;
        }

        return {};
    }
};