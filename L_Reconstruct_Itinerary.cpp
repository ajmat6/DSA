class Solution {
public:
    void DFS(unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adjList, string node, vector<string>& ans)
    {
        auto &pq = adjList[node];

        // traversing over adjList of a node and popping each visited city so that we will not dive into a never ending loop:P
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            DFS(adjList, top, ans);
        }
        ans.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Create adjacancy list:
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adjList;
        for(auto i: tickets)
        {
            string u = i[0];
            string v = i[1];

            adjList[u].push(v);
        }

        // DFS:
        vector<string> ans;
        DFS(adjList, "JFK", ans);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};