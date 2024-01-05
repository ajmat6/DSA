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
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
const int mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        ll n, m;
        cin >> n >> m;

        // create adjacancy list:
        unordered_map<ll, list<pll>> adjList;
        for(ll i=0; i<m; i++)
        {
            ll a, b, c;
            cin >> a >> b >> c;

            adjList[a].pb({b, c});
            adjList[b].pb({a, c});
        }

        vll s (n);
        for(ll i=0; i<n; i++) cin >> s[i];

        vector<vll> dist (n + 1, vll (n + 1, 1e17)); // <node, slow>
        vector<vll> vis (n + 1, vll (n + 1, 0));
        priority_queue<vll, vector<vll>, greater<vll>> pq;
        dist[1][0] = 0;
        pq.push({0, 1, 0});

        ll ans;
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            ll distt = top[0];
            ll node = top[1];
            ll slow = top[2];
            ll speed = s[top[2]];

            if(node == n)
            {
                ans = distt;
                break;                            
            }

            vis[node][slow] = 1;
            for(auto i: adjList[node])
            {
                ll to = i.F;
                ll len = i.S;

                if(vis[to][slow] == 0 && dist[to][slow] > distt + (speed * 1LL * len))
                {
                    dist[to][slow] = distt + (speed * 1LL * len);
                    int newSpeed = min(speed, s[to - 1]);
                    if(newSpeed == speed) newSpeed = slow;
                    else newSpeed = to - 1;
                    pq.push({dist[to][slow], to, newSpeed});
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}