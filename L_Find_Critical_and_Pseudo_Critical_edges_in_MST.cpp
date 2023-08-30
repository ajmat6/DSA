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

        if(uprtU == uprtV) return false;

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

        return true;
    }

    int getSize(int n)
    {
        return size[ultimateParent(n)];
    }
};
class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b)
    {
        return a[2] < b[2];
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // inserting index into the edges:
        for(int i=0; i<edges.size(); i++)
        {
            edges[i].push_back(i);
        }

        // Finding weight of MST:
        // sorting based on weights of the edges
        sort(edges.begin(), edges.end(), compare);

        DisjointSet ds1(n);
        int mstWeight = 0; // to store weight of min spanning tree
        for(int i=0; i<edges.size(); i++)
        {
            if(ds1.unionBySize(edges[i][0], edges[i][1]))
            {
                mstWeight += edges[i][2];
            }
        }

        // finding all possible MSTs:
        // we will take and not take a paticular edge and try constructing and MST if possible:
        vector<int> critical;
        vector<int> pseudoCritical;

        for(int i=0; i<edges.size(); i++)
        {
            // not take case:
            DisjointSet ds2(n);
            int TakeWeight = 0;
            for(int j=0; j<edges.size(); j++)
            {
                if(i != j && ds2.unionBySize(edges[j][0], edges[j][1]))
                {
                    TakeWeight += edges[j][2];
                }
            }

            // if I did not take an edge and weight of the MST(if formed) is greater than our min MST, it is a critical edge and store its index:
            if(ds2.getSize(0) != n || TakeWeight > mstWeight) // not forming min MST
            {
                critical.push_back(edges[i][3]);
            }

            // if not taking an edge is stll forming an MST with weight as mstWeight, then checking if it is pseudocritical edge:
            else
            {
                // taking weight age and checking if it does not appear in all the possible msts
                DisjointSet ds3(n);
                int NotTakeWeight = edges[i][2];
                ds3.unionBySize(edges[i][0], edges[i][1]);
                for(int j=0; j<edges.size(); j++)
                {
                    if(i != j && ds3.unionBySize(edges[j][0], edges[j][1]))
                    {
                        NotTakeWeight += edges[j][2];
                    }
                }

                if(NotTakeWeight == mstWeight)
                {
                    pseudoCritical.push_back(edges[i][3]);
                }
            }
        }

        return {critical, pseudoCritical};
    }
};