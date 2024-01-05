class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        // create adjcancy list:
        unordered_map<int, list<int>> adjList;
        vector<int> ans;
        for(auto i: ap)
        {
            int u = i[0];
            int v = i[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // find node which have only one adjcant element:
        int first;
        for(auto i: adjList)
        {
            if(i.second.size() == 1) first = i.first;
        }

        ans.push_back(first);
        queue<int> q;
        set<int> vis;
        q.push(first);
        vis.insert(first);

        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            for(auto i: adjList[front])
            {
                if(vis.find(i) == vis.end())
                {
                    ans.push_back(i);
                    vis.insert(i);
                    q.push(i);
                }
            }
        }

        return ans;
    }
};