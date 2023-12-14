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

    int n, m;
    cin >> n >> m;

    unordered_map<int, vi> adjList;

    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }


    queue<int> q;
    q.push(1);
    vi vis (n + 1, 0);
    vis[1] = 1;
    vi parent (n + 1, 0);
    parent[1] = -1;

    bool found = false;
    vi path;
    int start = -1;
    int end = -1;
    while(!q.empty())
    {
        int node = q.front(); q.pop();
        for(auto i: adjList[node])
        {
            if(vis[i] == 1 && i != parent[node])
            {
                found = true;
                path.pb(i);
                path.pb(node);
                start = node;
                end = i;
                break;
            }

            else if(vis[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
                parent[i] = node;
            }
        }
        if(found) break;
    }

    if(!found) cout << "IMPOSSIBLE";
    else
    {
        while(1)
        {
            path.pb(parent[start]);
            start = parent[start];

            if(start == end) break;
        }

        cout << path.size() << "\n";
        for(auto i: path) cout << i << " ";
    }

    return 0;
}