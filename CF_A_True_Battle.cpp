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

        string s;
        cin >> s;

        int ones = 0;
        int zero = 0;
        for(auto i: s) {
            if(i == '0') zero++;
            else ones++;
        }

        bool poss = false;
        for(int i=1; i<n; i++) {
            if(s[i] == '1' && s[i - 1] == '1') {
                poss = true;
                break;
            }
        }

        if(s[0] == '1' || s[n - 1] == '1') cout << "YES\n";
        else if(poss) cout << "YES\n";
        else if(ones >= zero) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}