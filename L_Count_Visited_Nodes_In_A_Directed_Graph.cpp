class Solution {
public:
    void DFS1(vector<int>& edges, unordered_map<int, int>& adjList, vector<int>& vis, int node, stack<int>& st)
    {
        vis[node] = 1;

        if(!vis[adjList[node]])
        {
            DFS1(edges, adjList, vis, adjList[node], st);
        }

        st.push(node);
    }

    void DFS2(vector<int>& vis, vector<int>& whichSCC, int totalSCC, unordered_map<int, list<int>>& adjList, int node)
    {
        vis[node] = 1;
        whichSCC[node] = totalSCC;

        for(auto i: adjList[node])
        {
            if(!vis[i])
            {
                DFS2(vis, whichSCC, totalSCC, adjList, i);
            }
        }
    }

    vector<int> countVisitedNodes(vector<int>& edges) {
        unordered_map<int, int> adjList;
        for(int i=0; i<edges.size(); i++)
        {
            adjList[i] = edges[i];
        }

        stack<int> st;
        vector<int> vis (edges.size(), 0);
        
        // finding topo sort:
        for(int i=0; i<edges.size(); i++)
        {
            if(!vis[i])
            {
                DFS1(edges, adjList, vis, i, st);
            }
        }

        // reverse the graph:
        unordered_map<int, list<int>> mp;
        for(int i=0; i<edges.size(); i++)
        {
            mp[edges[i]].push_back(i);
        }

        // finding no of scc's:
        vector<int> whichSCC (edges.size(), 0); // which node belong to which scc
        int totalSCC = 0; // total scc
        vector<int> vis2 (edges.size(), 0);

        while(!st.empty())
        {
            int top = st.top();
            st.pop();

            if(!vis2[top])
            {
                DFS2(vis2, whichSCC, totalSCC, mp, top);
                totalSCC++;
            }
        }

        // count no of node in each scc:
        unordered_map<int, list<int>> sccList;
        vector<int> countNodes (totalSCC);

        for(int i=0; i<whichSCC.size(); i++)
        {
            sccList[whichSCC[i]].push_back(i); // konse scc se konse nodes belong karte he:
        }

        for(int i=totalSCC-1; i>=0; i--)
        {
            countNodes[i] = sccList[i].size();
            for(auto node: sccList[i])
            {
                if(whichSCC[edges[node]] != i)
                {
                    countNodes[i] += countNodes[whichSCC[edges[node]]];
                }
            }
        }

        vector<int> ans (edges.size(), 0);
        for(int i=0; i<edges.size(); i++)
        {
            ans[i] = countNodes[whichSCC[i]];
        }

        return ans;
    }
};