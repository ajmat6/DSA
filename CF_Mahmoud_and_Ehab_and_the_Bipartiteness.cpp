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

void DFS(unordered_map<int, vi>& adjList, int node, vi& l, vi& r, int colour, int parent) {
    if(colour == 0) l.pb(node);
    else r.pb(node);
    for(auto i: adjList[node]) {
        if(i != parent) DFS(adjList, i, l, r, !colour, node);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    unordered_map<int, vi> adjList;
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;

        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    // using dfs -> dividing them into two groups and then finding out ans and removing already made edges:
    vi l; vi r;
    DFS(adjList, 1, l, r, 0, -1);
    ll ans = l.size() * r.size() - (n - 1);
    cout << ans;

    // colour them: using bfs bipartie concept
    // queue<int> q;
    // vi colour (n + 1, -1);
    // q.push(1);
    // colour[1] = 0;

    // int ones = 0;
    // int zero = 1;
    // while(!q.empty()) {
    //     int node = q.front(); q.pop();
    //     for(auto i: adjList[node]) {
    //         if(colour[i] == -1) {
    //             colour[i] = !colour[node];
    //             if(colour[i] == 1) ones++;
    //             else zero++;
    //             q.push(i);
    //         }
    //     }
    // }

    // // connect them:
    // ll ans = 0;
    // for(int i=1; i<=n; i++) {
    //     int oppo;
    //     if(colour[i] == 1) oppo = 0;
    //     else oppo = 1;

    //     int total = oppo == 0 ? zero : ones;
    //     ans += total - adjList[i].size();
    // }

    // cout << ans / 2;

    return 0;
}