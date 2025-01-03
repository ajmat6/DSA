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
        string s;
        string t;
        cin >> s;
        cin >> t;

        int count = 0;
        int i = 0; int j = 0;
        while(i < s.size() && j < t.size() && s[i] == t[i]) {
            count++;
            i++;
            j++;
        }

        ll ans = count + (s.size() - count) + (t.size() - count);
        if(count != 0) ans += 1;
        cout << ans << "\n";
    }

    return 0;
}