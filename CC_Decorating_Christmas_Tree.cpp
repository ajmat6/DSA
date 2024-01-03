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
        int n, large, small;
        cin >> n >> large >> small;

        // using small and large:
        int usingSmall = small / 3;
        if(large >= usingSmall) large -= usingSmall;
        else
        {
            usingSmall = large;
            large = 0;
        }

        n -= usingSmall;

        if(n <= 0)
        {
            cout << "YES\n";
            continue;
        }
        else
        {
            if(large == 0) cout << "NO\n";
            else
            {
                int usingLarge = large / 2;
                n -= usingLarge;

                if(n <= 0) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }

    return 0;
}