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
        ll n, k, d;
        cin >> n >> k >> d;

        vll a (n);
        vll b (k);
        for(int i=0; i<n; i++) cin >> a[i];
        for(ll i=0; i<k; i++) cin >> b[i];

        int day = 1;
        ll ans = 0;
        while(day <= min(d, n * 2))
        {
            int count = 0;
            for(int i=0; i<n; i++)
            {
                if(a[i] == i + 1) count++;
            }

            ans = max(ans, count + (d - day) / 2); // if I do 0 at this step 

            int index = (day - 1) % k;
            int what = b[index] - 1;
            for(int i=0; i<=what; i++) a[i] += 1;

            day++;
        }

        cout << ans << "\n";
    }

    return 0;
}