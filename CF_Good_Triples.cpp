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
        ll n;
        cin >> n;

        string s = to_string(n);
        ll ans = 1;
        for(int i=s.size()-1; i>=0; i--)
        {
            // count no of ways of each digit:
            ll count = 0;
            for(int j=0; j<=9; j++)
            {
                for(int k=0; k<=9; k++)
                {
                    for(int l=0; l<=9; l++)
                    {
                        if(j + k + l == s[i] - '0') count++;
                    }
                }
            }

            ans *= count;
        }
        
        cout << ans << "\n";
    }

    return 0;
}