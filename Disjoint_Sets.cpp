#include<iostream>
#include<vector>
using namespace std;

class DisjointSet
{
    // rank and parent vectors:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

    public:

    DisjointSet(int n) // n is no of components and the no of nodes we are going to get in Dijoint Set DS
    {
        rank.resize(n+1, 0); // n+1 is done for 1 based indexing and intially rank of all the componenets is zero
        parent.resize(n+1);
        size.resize(n+1);

        // intilizing parent and size:
        for(int i=0;  i<parent.size(); i++)
        {
            parent[i] = i;
            size[i] = 1; // initially size of every component is 1
        }
    }

    // function to find ultimate parent: Storing in parent before returning the function is doing path compresssion here
    int findUltimateParent(int node)
    {
        // base case: when parent of node is itself then return node:
        if(node == parent[node]) return node;

        // recursive call to find the parent of the node's parent and storing before returning as its parent:
        else return parent[node] = findUltimateParent(parent[node]);
    }

    // function to do union by rank: Two nodes are given and we have to do their union
    void unionByRank(int u, int v)
    {
        // step 1 -> find ultimate parent of u and v:
        int parentOfU = findUltimateParent(u);
        int parentOfV = findUltimateParent(v);

        // if ultimate parent of u and v are same then they are already in union:
        if(parentOfU == parentOfV) return;

        // step 2 -> find ranks of their ultimate parent:
        int rankOfParentOfU = rank[parentOfU];
        int rankOfParentOfV = rank[parentOfV];

        // if rank of u's parent is less than v's , then make parent of u's parent as v's parent:
        if(rankOfParentOfU < rankOfParentOfV)
        {
            parent[parentOfU] = parentOfV;
        }

        // parent of v's parent becomes u's parent:
        else if(rankOfParentOfU > rankOfParentOfV)
        {
            parent[parentOfV] = parentOfU;
        }

        // if ranks of both u's and v's parent are same, then you can make anyone as others parent;
        else
        {
            parent[parentOfV] = parentOfU;
            rank[parentOfU]++;
        }
    }

    void unionBySize(int u, int v)
    {
        // step 1 -> find ultimate parent of u and v:
        int parentOfU = findUltimateParent(u);
        int parentOfV = findUltimateParent(v);

        // if ultimate parent of u and v are same then they are already in union:
        if(parentOfU == parentOfV) return;

        // step 2 -> find size of their ultimate parent:
        int sizeOfParentOfU = size[parentOfU];
        int sizeOfParentOfV = size[parentOfV];

        if(sizeOfParentOfU > sizeOfParentOfV)
        {
            parent[parentOfV] = parentOfU;
            size[parentOfU] += size[parentOfV]
        }

        // else case includes both the cases when size of u's and v's parents are equal and size of u's parent is lesser
        else
        {
            parent[parentOfU] = parentOfV;
            size[parentOfV] += size[parentOfU];
        }
    }
};

int main()
{
    // DisjointSet ds(7); // forming Disjoint Set data structur of 7 nodes

    // union of nodes:
    // ds.unionByRank(1, 2);
    // ds.unionByRank(2, 3);
    // ds.unionByRank(4, 5);
    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6);
    // ds.unionByRank(3, 7);

    // before doing union of 3 and 7, checking if 3 and 7 belong to same component or not:
    // cout << "Before doing union of 3 and 7, checking if 3 and 7 belong to same component" << endl;
    // if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout << "Yes! they belong to same component" << endl;
    // else cout << "No! they do not belong to same component" << endl;

    // ds.unionByRank(3, 7);

    // after doing union of 3 and 7, checking if 3 and 7 belong to same component or not:
    // cout << "After doing union of 3 and 7, checking if 3 and 7 belong to same component" << endl;
    // if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout << "Yes! they belong to same component" << endl;
    // else cout << "No! they do not belong to same component" << endl;



    // Union by size:
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // ds.unionBySize(3, 7);
    
    // before doing union of 3 and 7, checking if 3 and 7 belong to same component or not:
    cout << "Before doing union by union by size of 3 and 7, checking if 3 and 7 belong to same component" << endl;
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout << "Yes! they belong to same component" << endl;
    else cout << "No! they do not belong to same component" << endl;

    ds.unionBySize(3, 7);

    // after doing union of 3 and 7, checking if 3 and 7 belong to same component or not:
    cout << "After doing union by union by size of 3 and 7, checking if 3 and 7 belong to same component" << endl;
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout << "Yes! they belong to same component" << endl;
    else cout << "No! they do not belong to same component" << endl;

    return 0;
}