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

    while(t--)
    {
        int n, x;
        cin >> n >> x;

        string s;
        cin >> s;

        int ans = 0;
        bool poss = true;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '0' && ans == 0)
            {
                poss = false;
                break;
            }
            else if(s[i] == '0' && ans != 0) ans -= 1;
            else if(s[i] == '1') ans += x;
        }

        if(poss) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}