class DisjointSet
{
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i=0; i<parent.size(); i++) parent[i] = i;
    }

    int ultimateParent(int n)
    {
        if(parent[n] == n) return n;
        else return parent[n] = ultimateParent(parent[n]);
    }

    void unionBySize(int u, int v)
    {
        int ulpU = ultimateParent(u);
        int ulpV = ultimateParent(v);

        if(ulpU == ulpV) return;

        if(size[ulpU] > size[ulpV])
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        // // find each possible edge and weight of it:
        // vector<pair<int, pair<int, int>>> adjList;
        // for(int i=0; i<points.size(); i++)
        // {
        //     for(int j=i+1; j<points.size(); j++)
        //     {
        //         int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        //         adjList.push_back({weight, {i, j}});
        //     }
        // }

        // // sort the adjList according to the weight for minimum spanning tree:
        // sort(adjList.begin(), adjList.end());

        // DisjointSet ds(points.size());
        // int ans = 0;

        // // traversing throught the edges and finding MST:
        // for(int i=0; i<adjList.size(); i++)
        // {
        //     int u = adjList[i].second.first;
        //     int v = adjList[i].second.second;
        //     int w = adjList[i].first;

        //     if(ds.ultimateParent(u) != ds.ultimateParent(v))
        //     {
        //         ds.unionBySize(u, v);
        //         ans += w;
        //     }
        // }

        // return ans;


        // Using Prims Alogorithm:

        // Creating adjlist:
        unordered_map<int, list<pair<int, int>>> adjList; // <node, {adjNode, weight}>
        for(int i=0; i<points.size(); i++)
        {
            for(int j=i+1; j<points.size(); j++)
            {
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adjList[i].push_back({j, weight});
                adjList[j].push_back({i, weight});
            }
        }

        // vector<int> parent (points.size(), -1);
        vector<int> key (points.size(), INT_MAX);
        vector<bool> vis (points.size(), false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // inserting 0th node into pq:
        pq.push({0, 0});
        key[0] = 0;

        int cost = 0;

        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int weight = top.first;
            int node = top.second;
            // int parentNode =  top.second.second;

            if(vis[node] == true) continue;
            
            vis[node] = true;

            cost += weight;

            for(auto i: adjList[node])
            {
                int adjNode = i.first;
                int adjWeight = i.second;

                if(!vis[adjNode] && adjWeight < key[adjNode])
                {
                    pq.push({adjWeight, adjNode});
                    key[adjNode] = adjWeight;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<key.size(); i++)
        {
            ans += key[i];
        }

        return ans;
    }
};