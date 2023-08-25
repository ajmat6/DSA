class Solution {
public:
    // Class for disjoint sets:
    class DisjointSets 
    {
        vector<int> parent;
        vector<int> rank;

        public: 

        DisjointSets(int n)
        {
            parent.resize(n+1);
            rank.resize(n+1, 0);

            for(int i=0; i<parent.size(); i++) parent[i] = i;
        }

        int ultimateParent(int n)
        {
            if(parent[n] == n) return n;
            else return parent[n] = ultimateParent(parent[n]);
        }

        void UnionByRank(int u, int v)
        {
            int parentOfU = parent[u];
            int parentOfV = parent[v];

            if(rank[parentOfU] < rank[parentOfV])
            {
                parent[parentOfU] = parentOfV;
            }

            else if(rank[parentOfU] > rank[parentOfV])
            {
                parent[parentOfV] = parentOfU;
            }

            else
            {
                parent[parentOfU] = parentOfV;
                rank[parentOfV]++;
            }
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {
        // find no of individual components that are not connected to each other
        // No of wires to connect them will be nc - 1 where nc is above line ans
        // find no of extra edges: edge will be extra when their ultimate parent is same:

        DisjointSets ds(n);

        // finding extra edges:
        int extra = 0;
        for(auto x: connections)
        {
            int u = x[0];
            int v = x[1];

            if(ds.ultimateParent(u) == ds.ultimateParent(v)) extra++;
            ds.UnionByRank(u, v);
        }

        // individual components: Those whost ultimate parent is themselves:
        int compo = 0;
        for(int i=0; i<n; i++)
        {
            if(ds.ultimateParent(i) == i) compo++;
        }

        // finding possibility of no of operations:
        if(extra >= compo - 1) return compo - 1;
        else return -1;
    }
};