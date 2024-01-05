#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;

ll DFS(ll node, ll total, unordered_map<ll, list<ll>>& adjList, ll m, vector<ll>& cats, ll parent)
{
    if(total > m) return 0;

    ll ans = 0;
    ll flag = 0; // for leaf node track
    for(auto i: adjList[node])
    {
        if(cats[i] == 1 && i != parent)
        {
            flag = 1;
            ans += DFS(i, total + 1, adjList, m, cats, node);
        } 
        else if(i != parent)
        {
            flag = 1;
            ans += DFS(i, 0, adjList, m, cats, node);
        } 
    }

    if(flag == 0) ans++; // if leaf node:

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll v, m;
    cin >> v >> m;

    vector<ll> cats (v + 1, 0);
    for(int i=1; i<=v; i++) cin>> cats[i];

    vector<vector<ll>> edges (v - 1, vector<ll> (2));
    for(ll i=0; i<edges.size(); i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    // create adjacancy list:
    unordered_map<ll, list<ll>> adjList;
    for(auto i: edges)
    {
        ll u = i[0];
        ll v = i[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    // visited vector for the track of already visited nodes:
    cout << DFS(1, cats[1], adjList, m, cats, -1);

    return 0;
}