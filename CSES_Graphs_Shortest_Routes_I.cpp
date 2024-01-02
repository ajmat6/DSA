#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
const int mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;
    unordered_map<ll, vector<pll>> adjList;
    for(int i=0; i<m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        adjList[a].pb({b, c});
    }

    vll dist (n + 1, LLONG_MAX);
    vll vis (n + 1, 0);
    priority_queue<pll, vpll, greater<pll>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty())
    {
        auto top = pq.top(); pq.pop();
        ll node = top.S;
        ll distt = top.F;

        if(vis[node]) continue;

        vis[node] = 1;
        for(auto &i: adjList[node])
        {
            ll to = i.F;
            ll edge = i.S;

            if(!vis[to] && distt + edge < dist[to])
            {
                dist[to] = distt + edge;
                pq.push({dist[to], to});
            }
        }
    }

    for(ll i=1; i<(n + 1); i++) cout << dist[i] << " ";

    return 0;
}