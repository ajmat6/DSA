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

    int com, conn;
    cin >> com >> conn;

    unordered_map<int, vi> adjList;
    for(int i=0; i<conn; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    // BFS:
    vi res;
    vi parent (com + 1);
    int ans = 1;

    queue<int> q;
    vi vis (com + 1);
    q.push(1);
    vis[1] = 1;

    bool found = false;
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            int node = q.front(); q.pop();

            // if last computer is found:
            if(node == com)
            {
                found = true;
                break;
            }
            
            for(auto i: adjList[node])
            {
                if(!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                    parent[i] = node;
                }
            }
        }
        
        if(found) break;
        ans++;
    }

    if(!vis[com]) cout << "IMPOSSIBLE";
    else
    {
        // finding path:
        res.pb(com);
        int curr = com;
        while(1)
        {
            if(curr == 1) break;
            res.pb(parent[curr]);
            curr = parent[curr];
        }
        reverse(res.begin(), res.end());
        cout << ans << "\n";
        for(auto i: res) cout << i << " ";
    }

    return 0;
}