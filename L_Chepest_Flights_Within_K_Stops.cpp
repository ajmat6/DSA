class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // create adjacency list:
        unordered_map<int, list<pair<int, int>>> mp; // <from, <to, price>>
        for(int i=0; i<flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            mp[u].push_back({v, w});
        }

        if(mp.find(src) == mp.end()) return -1;

        // making a price vector (like distance vector)
        vector<int> price (n, INT_MAX);

        // initialzing source station:
        price[src] = 0;

        // making a queue to track min stop:
        queue<pair<int, pair<int, int>>> q; // <stop no, <station no, price>>
        q.push({0, {src, 0}});

        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            int stop = front.first;
            int station = front.second.first;
            int cost = front.second.second;

            for(auto i: mp[station])
            {
                int adjStation = i.first;
                int adjCost = i.second;

                // price and stops check:
                if(cost + adjCost < price[adjStation] && stop <= k)
                {
                    price[adjStation] = cost + adjCost;
                    q.push({stop + 1, {adjStation, cost + adjCost}});
                }
            }
        }

        // after doing above operation, checking for destionation:
        if(price[dst] == INT_MAX) return -1;
        else return price[dst];
    }
};