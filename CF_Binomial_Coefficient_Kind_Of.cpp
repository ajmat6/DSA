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

ll cal(ll power) {
    ll ans = 1;
    ll a = 2;
    while(power != 0) {
        if(power % 2 == 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        power = power / 2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int p;
    cin >> p;

    vll ni(p), ki(p);
    for(int i=0; i<p; i++) cin >> ni[i];
    for(int i=0; i<p; i++) cin >> ki[i];
    for(int i=0; i<p; i++) cout << cal(ki[i]) << "\n";

    return 0;
}