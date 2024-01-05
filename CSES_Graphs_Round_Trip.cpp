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
int start = -1;
int endd = -1;
bool found = false;
vi ans;

void DFS(int node, vi& vis, vi& parent, unordered_map<int, vi>& adjList)
{
    for(auto i: adjList[node])
    {
        // if cycle found
        if(vis[i] == 1 && i != parent[node])
        {
            ans.pb(i);
            start = node;
            endd = i;
            found = true;
            return;
        }

        else if(vis[i] == 0)
        {
            vis[i] = 1;
            parent[i] = node;
            DFS(i, vis, parent, adjList);
            if(found) return; // if cycle found don't do remaining calls
        }
    }

    return;
}

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


    vi parent (n + 1);
    vi vis (n + 1);
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            parent[i] = -1;
            DFS(i, vis, parent, adjList);
            if(found) break;
        }
    }

    if(!found) cout << "IMPOSSIBLE";
    else
    {
        while(start != endd)
        {
            ans.pb(start);
            start = parent[start];
        }   
        ans.pb(endd);
        cout << ans.size() << "\n";
        for(auto i: ans) cout << i << " ";
    }

    return 0;
}