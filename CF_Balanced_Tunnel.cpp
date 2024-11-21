b#include<bits/stdc++.h>
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

    int n;
    cin >> n;

    vi enter (n); vi exit (n);
    for(int i=0; i<n; i++) cin >> enter[i];
    for(int i=0; i<n; i++) cin >> exit[i];

    vi e(n + 1);
    for(int i=0; i<n; i++) {
        e[exit[i]] = i + 1;
    }

    ll curr = INT_MIN; ll ans = 0;
    for(int i=0; i<n; i++) {
        int car = enter[i];
        if(e[car] > curr) curr = e[car]; // curr car's exit no should be greater than all its earlier cars exit no (max of them)
        else ans++;
    }

    cout << ans;
    
    return 0;
}