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

    int t;
    cin >> t;

    while(t--) {
        int a, b, c, m;
        cin >> a >> b >> c >> m;


        if(a == b || a == c || b == c) cout << "YES\n";
        else if(abs(a - b) <= m || abs(a - c) <= m || abs(b - c) <= m) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}