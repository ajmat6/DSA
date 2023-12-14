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

    int p, f;
    cin >> p >> f;

    unordered_map<int, vi> adjList;
    for(int i=0; i<f; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }

    // Biparatite graph concept:
    vi vis (p + 1);
    queue<int> q;

    bool notPossible = false;
    for(int i=1; i<=p; i++)
    {
        if(vis[i] == 0)
        {
            q.push(i);
            vis[i] = 1;

            while(!q.empty())
            {
                int node = q.front(); q.pop();
                int nodeColour = vis[node];

                for(auto i: adjList[node])
                {
                    if(vis[i] == 0)
                    {
                        if(nodeColour == 1) vis[i] = 2;
                        else vis[i] = 1;
                        q.push(i);
                    }

                    else
                    {
                        if(vis[i] == nodeColour)
                        {
                            notPossible = true;
                            break;
                        }
                    }
                }

                if(notPossible) break;
            }
        }

        if(notPossible) break;
    }

    if(notPossible) cout << "IMPOSSIBLE";
    else
    {
        for(int i=1; i<vis.size(); i++) cout << vis[i] << " ";
    }

    return 0;
}