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

int gcd(int a, int b)
{
    if(a == b) return a;
    if(a > b) return gcd(a - b, b);
    else return gcd(a, b - a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        ll a, b;
        cin >> a >> b;

        ll hcf = gcd(a, b);
        ll lcm = (a * 1LL * b) / hcf;

        if(b % a == 0) cout << b * (b / a) << "\n";
        else cout << lcm << "\n";
    }
    

    return 0;
}