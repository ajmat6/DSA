class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int, list<int>> adjList;
        set<pair<int, int>> st;

        for(auto i: roads)
        {
            int u = i[0];
            int v = i[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            st.insert({u, v});
        }

        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int temp = adjList[i].size() + adjList[j].size();

                if(st.find({i, j}) != st.end() || st.find({j, i}) !=  st.end())
                {
                    temp -= 1;
                }

                ans = max(ans, temp);
            }
        }

        return ans;
    }
};