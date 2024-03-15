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
        ll n;
        cin >> n;

        ll power = 0;
        ll val = 0;
        while(true) {
            val = pow(2, power);
            if(n <= val) break;
            else power++;
        }

        if(n == val) cout << val << "\n";
        else cout << pow(2, power - 1) << "\n";
    }

    return 0;
}