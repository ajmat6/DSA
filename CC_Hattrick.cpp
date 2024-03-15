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

    while(t--)
    {
        char a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;

        // cout << a << b << c << d << e << f;
        if(a == b && b == c && a == 'W') cout << "YES\n";
        else if(b == c && c == d && c == 'W') cout << "YES\n";
        else if(c == d && d == e && e == 'W') cout << "YES\n";
        else if(d == e && e == f && f == 'W') cout << "YES\n";
        else cout << "NO\n";     
    }

    return 0;
}