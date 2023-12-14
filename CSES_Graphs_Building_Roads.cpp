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

void dfs(int node, unordered_map<int, vector<int>>& adjList, vi& vis)
{
    for(auto i: adjList[node])
    {
        if(vis[i] == 0)
        {
            vis[i] = 1;
            dfs(i, adjList, vis);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int city, roads;
    cin >> city >> roads;

    // create adjacancy list:
    unordered_map<int , vector<int>> adjList;
    for(int i=0; i<roads; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].pb(b);
        adjList[b].push_back(a);
    }

    vi vis (city + 1);
    vvi result;
    int ans = 0;
    int prev = 1; // this will store the last city no which was not connected to anyone. Now if next time a city comes after prev + any_no then because cities less than any_no are already connected, you can build road b/w prev and any_no city.

    for(int i=1; i<=city; i++)
    {
        if(!vis[i])
        {
            if(i == 1 && adjList.find(i) == adjList.end())
            {
                vis[1] = 1;
                result.pb({1, 2});
                adjList[1].pb(2);
                adjList[2].pb(1);
                dfs(1, adjList, vis);
                ans++;
            }

            else if(i == 1 && adjList.find(i) != adjList.end())
            {
                vis[1] = 1;
                dfs(1, adjList, vis);
            }

            else
            {
                ans++;
                result.pb({prev, i});
                adjList[i].pb(prev);
                adjList[prev].pb(i);
                prev = i;
                vis[i] = 1;
                dfs(i, adjList, vis);
            }
        }
    }

    cout << ans << "\n";
    for(auto i: result)
    {
        cout << i[0] << " " << i[1] << "\n";
    }

    return 0;
}