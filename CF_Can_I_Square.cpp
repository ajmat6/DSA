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

    ll t;
    cin >> t;

    while(t--)
    {
        ll n; 
        cin >> n;

        vll buc (n);
        for(ll i=0; i<n; i++) cin >> buc[i];

        ll sum = 0;
        for(ll i=0; i<n; i++) sum += buc[i];

        ll sqRoot = sqrt(sum); // it will give an integer value (will convert decimal to floor becoz of ll and not float)

        if(sqRoot * 1LL * sqRoot == sum) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}