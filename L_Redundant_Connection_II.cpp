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

    bool unionBySize(int u, int v)
    {
        int uprtU = ultimateParent(u);
        int uprtV = ultimateParent(v);

        if(uprtU == uprtV)
        {
            return true;
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

        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        vector<int> indegree (n+1, -1);
        int bl1 = -1;
        int bl2 = -1;

        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            if(indegree[v] == -1)
            {
                indegree[v] = i;
            }

            // if indegree is not -1 then it is 2 parent case:
            else
            {
                bl1 = i;
                bl2 = indegree[v];
            }
        }

        // if bl1 and 2 are -1, then cycle present case is there:
        if(bl1 == -1 && bl2 == -1)
        {
            for(auto i: edges)
            {
                int u = i[0];
                int v = i[1];

                bool result = ds.unionBySize(u, v);
                if(result) return {i[0], i[1]};
            }
        }

        // if 2 parents case is there , then check for 2 parents + cycle case
        // consider after edge as answer and check if cycle is present then it is not an ans, otherwise it is the ans:
        else
        {
            // check if cycle is present:
            for(int i=0; i<edges.size(); i++)
            {
                if(i == bl1) continue;
                int u = edges[i][0];
                int v = edges[i][1];

                bool result = ds.unionBySize(u, v);

                // cycle detected, means ans you have considered  is not valid, there is still cycle in the tree. so return bl2:
                if(result) return {edges[bl2][0], edges[bl2][1]};
            }
        }

        return {edges[bl1][0], edges[bl1][1]};
    }
};