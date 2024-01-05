class DisjointSet
{
    public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0; i<parent.size(); i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int ultparent(int n)
    {
        if(parent[n] == n) return n;
        else return parent[n] = ultparent(parent[n]);
    }

    void unionBySize(int u, int v)
    {
        int ulpU = ultparent(u);
        int ulpV = ultparent(v);

        if(ulpU == ulpV) return;

        if(size[ulpU] >= size[ulpV])
        {
            parent[ulpV] = ulpU;
            size[ulpU] += size[ulpV];
        }

        else
        {
            parent[ulpU] = ulpV;
            size[ulpV] += size[ulpU];
        }
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // Using DFS:

        // unordered_map<int, list<int>> adjList;
        // vector<int> parent (n, -1);
        // vector<int> vis (n, 0);

        // // Create adjacancy list:
        // for(int i=0; i<n; i++)
        // {
        //     int left = leftChild[i];
        //     int right = rightChild[i];

        //     if(left != -1)
        //     {
        //         if(parent[left] != -1) return false; // if a node already have its parent
        //         else
        //         {
        //             adjList[i].push_back(left);
        //             parent[left] = i;
        //         }
        //     }

        //     if(right != -1)
        //     {
        //         if(parent[right] != -1) return false;
        //         else
        //         {
        //             adjList[i].push_back(right);
        //             parent[right] = i;
        //         }
        //     }
        // }

        // // now check there should be exactly one root node:
        // int root = -1;
        // for(int i=0; i<n; i++)
        // {
        //     if(parent[i] == -1)
        //     {
        //         if(root == -1) root = i;
        //         else return false;
        //     }
        // }

        // // if no node is parent node -> Example 3:
        // if(root == -1) return false;

        // // BFS traversal to check for valid binary tree:
        // queue<int> q;
        // q.push(root);
        // vis[root] = 1;

        // while(!q.empty())
        // {
        //     int front = q.front();
        //     q.pop();

        //     for(auto i: adjList[front])
        //     {
        //         if(!vis[i])
        //         {
        //             q.push(i);
        //             vis[i] = 1;
        //         }

        //         else return false; // already visited:
        //     }
        // }

        // // check each node should be visited:
        // for(int i=0; i<n; i++)
        // {
        //     if(vis[i] == 0) return false;
        // }

        // return true;


        // Using DisjointSets:
        DisjointSet ds(n);
        vector<int> vis (n, 0);
        // unordered_map<int, list<int>> adjList;
        // vector<int> parent (n, -1);
        // vector<int> vis (n, 0);

        // Create adjacancy list:
        for(int i=0; i<n; i++)
        {
            int left = leftChild[i];
            int right = rightChild[i];

            if(left != -1)
            {
                // one a node have two parents:
                if(ds.ultparent(left) == ds.ultparent(i) || vis[left] != 0)
                {
                    return false;
                }

                else
                {
                    ds.unionBySize(left, i);
                    vis[left] = 1;
                }
            }

            if(right != -1)
            {
                if(ds.ultparent(right) == ds.ultparent(i) || vis[right] != 0)
                {
                    return false;
                }

                else
                {
                    ds.unionBySize(right, i);
                    vis[right] = 1;
                }
            }
        }

        // checkinf root node:
        int ultimateParent = ds.ultparent(0);
        for(int i=1; i<n; i++)
        {
            if(ds.ultparent(i) != ultimateParent) return false;
        }

        return true;

        // // now check there should be exactly one root node:
        // int root = -1;
        // for(int i=0; i<n; i++)
        // {
        //     if(parent[i] == -1)
        //     {
        //         if(root == -1) root = i;
        //         else return false;
        //     }
        // }

        // // if no node is parent node -> Example 3:
        // if(root == -1) return false;

        // // BFS traversal to check for valid binary tree:
        // queue<int> q;
        // q.push(root);
        // vis[root] = 1;

        // while(!q.empty())
        // {
        //     int front = q.front();
        //     q.pop();

        //     for(auto i: adjList[front])
        //     {
        //         if(!vis[i])
        //         {
        //             q.push(i);
        //             vis[i] = 1;
        //         }

        //         else return false; // already visited:
        //     }
        // }

        // // check each node should be visited:
        // for(int i=0; i<n; i++)
        // {
        //     if(vis[i] == 0) return false;
        // }

        // return true;
    }
};