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
        int n;
        cin >> n;

        
        int f = INT_MIN; int s = INT_MIN;
        for(int i=2; i*i<=n; i++) {
            if(n % i == 0) {
                f = i;
                n /= f;
                break;
            }
        }

        if(f == INT_MIN) {
            cout << "NO\n";
            continue;
        }

        for(int i=2; i*i<=n; i++) {
            if(n % i == 0 && i != f) {
                s = i;
                n /= s;
                break;
            }
        }

        if(s == INT_MIN || n == f || n == s) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << f << " " << s << " " << n << "\n";
        }
    }

    return 0;
}