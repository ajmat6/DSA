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

    string s;
    cin >> s;

    ll wCount = 0; ll wows = 0; ll ans = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'o') {
            wows += wCount;
        }

        else if(i > 0 && s[i - 1] == 'v') {
            ans += wows;
            wCount++;
        }
    }

    cout << ans;

    return 0;
}