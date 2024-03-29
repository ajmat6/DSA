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


        vll p (n);
        for(int i=0; i<n; i++) cin >> p[i];

        if(n <= 2){
            cout << "-1\n";
            continue;
        }

        vll ans;
        
        for(int i=0; i<n; i++) {
            if(p[i] == 1) ans.pb(3);
            else if(p[i] == 3) ans.pb(1);
            else ans.pb(p[i]);
        }
        
        for(auto i: ans) cout << i << " ";
        cout << "\n";
    }

    return 0;
}