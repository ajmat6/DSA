#define MOD 1000000007;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // creating adjacency list:
        unordered_map<int, list<pair<int, int>>> mp;
        for(int i=0; i<roads.size(); i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];

            mp[u].push_back({v, t});
            mp[v].push_back({u, t});
        }

        // distance array work:
        vector<long long> dist (n, 1e15);
        dist[0] = 0;

        // ways array work:
        vector<long long> ways (n, 0);
        ways[0] = 1;

        // priority queue work:
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        q.push({0, 0}); // <dist, which node>

        while(!q.empty())
        {
            long long distance = q.top().first;
            int node = q.top().second;
            q.pop();

            for(auto i: mp[node])
            {
                int nextNode = i.first;
                long long distBtwn = i.second;

                // checking for distance update:
                if((distance + distBtwn) <= dist[nextNode])
                {
                    // if there is one more way to reach nextNode:
                    if(distance + distBtwn == dist[nextNode])
                    {
                        ways[nextNode] = (ways[nextNode] + ways[node]) % MOD;
                    }

                    // if you are  reaching nextNode for first time:
                    else
                    {
                        ways[nextNode] = ways[node];
                        dist[nextNode] = distance + distBtwn;
                        q.push({distance + distBtwn, nextNode});
                    }
                }
            }
        }

        return ways[n-1] % MOD;
    }
};