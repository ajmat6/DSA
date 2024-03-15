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

    while(t--) {
        ll n; string s;
        cin >> n; cin >> s;

        // creating lexicographically largest substring:
        vll lexico;
        for(ll i=0; i<n; i++) {
            while(lexico.size() > 0 && s[i] > s[lexico.back()]) lexico.pop_back();
            lexico.pb(i);
        }

        int dup = 0;
        for(ll i=1; i<lexico.size(); i++) {
            if(s[lexico[i]] == s[lexico[0]]) dup++;
        }

        for(ll i=0; i<lexico.size() / 2; i++) {
            swap(s[lexico[i]], s[lexico[lexico.size() - i - 1]]);
        }

        if(is_sorted(s.begin(), s.end())) cout << lexico.size() - dup - 1 << "\n";
        else cout << "-1\n";
    }

    return 0;
}