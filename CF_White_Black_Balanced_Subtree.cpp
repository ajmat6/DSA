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

pii solve(int n, unordered_map<int, vi>& adjList, string& s, int node, int parent, int& ans) {
    if(adjList[node].size() == 1 && adjList[node][0] == parent) {
        if(s[node - 1] == 'W') return {0, 1}; // black white
        else return {1, 0};
    }

    int black = 0; int white = 0;
    for(auto i: adjList[node]) {
        if(i != parent) {
            pii res = solve(n, adjList, s, i, node, ans);
            black += res.F;
            white += res.S;
        }
    }

    if(s[node - 1] == 'W') white++;
    else black++;

    if(black == white) ans++;
    return {black, white};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        unordered_map<int, vi> adjList;
        for(int i=0; i<n-1; i++) {
            int parent;
            cin >> parent;

            int node = i + 2;
            adjList[node].pb(parent);
            adjList[parent].pb(node);
        }

        string s;
        cin >> s;

        int ans = 0;
        solve(n, adjList, s, 1, -1, ans);
        cout << ans << "\n";
    }

    return 0;
}