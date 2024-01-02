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

    ll n, m, q;
    cin >> n >> m >> q;
    vector<vll> adjMatrix (n + 1, vll (n + 1, LLONG_MAX));
    for(int i=0; i<m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        adjMatrix[a][b] = min(adjMatrix[a][b], c);
        adjMatrix[b][a] = min(adjMatrix[b][a], c);
    }

    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<=n; j++)
        {
            if(i == j) adjMatrix[i][j] = 0;
        }
    }

    // floyd warshall algo:
    for(ll via=1; via<=n; via++)
    {
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=n; j++)
            {
                if(adjMatrix[i][via] != LLONG_MAX && adjMatrix[via][j] != LLONG_MAX) adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);
            }
        }
    }

    for(ll i=0; i<q; i++)
    {
        ll a, b;
        cin >> a >> b;

        // vll dist (n + 1, LLONG_MAX);
        // vll vis (n + 1, 0);
        // priority_queue<pll, vpll, greater<pll>> pq;
        // pq.push({0, a});
        // dist[a] = 0;

        // while(!pq.empty())
        // {
        //     auto top = pq.top(); pq.pop();
        //     ll node = top.S;
        //     ll distt = top.F;

        //     if(vis[node]) continue;
        //     if(node == b) break;

        //     vis[node] = 1;
        //     for(auto &i: adjList[node])
        //     {
        //         ll to = i.F;
        //         ll edge = i.S;

        //         if(!vis[to] && distt + edge < dist[to])
        //         {
        //             dist[to] = distt + edge;
        //             pq.push({dist[to], to});
        //         }
        //     }
        // }

        adjMatrix[a][b] = adjMatrix[a][b] == LLONG_MAX ? -1 : adjMatrix[a][b];
        cout << adjMatrix[a][b] << "\n";
    }


    return 0;
}