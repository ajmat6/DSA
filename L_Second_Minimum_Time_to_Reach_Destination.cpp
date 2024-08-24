class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int, vector<int>> adjList;
        for(auto i: edges) {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }

        // find the least no of edges that you have to traverse to reach n:
        priority_queue<pair<int, int>,  vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist1 (n + 1, INT_MAX), dist2 (n + 1, INT_MAX);
        pq.push({0, 1}); dist1[1] = 0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int distt = pq.top().first; pq.pop();

            if(node == n) break;
            for(auto i: adjList[node]) {
                if(distt + 1 < dist1[i]) {
                    dist2[i] = dist1[i];
                    dist1[i] = distt + 1;
                    pq.push({dist1[i], i});
                }

                // for second min edges:
                else if(distt + 1 > dist1[i] && distt + 1 < dist2[i]) {
                    dist2[i] = distt + 1;
                    pq.push({distt + 1, i});
                }
            }
        }

        // find time:
        int total = dist2[n] == INT_MAX ? dist1[n] + 2 : dist2[n];
        cout << total;
        int currTime = 0;
        while(true) {
            currTime += time;
            total -= 1;
            if(total == 0) break;
            int quo = currTime / change;
            int rem = currTime % change;
            if(quo % 2 == 1) currTime += change - rem;
        }
        return currTime;
    }
};
