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
        int n;
        cin >> n;

        vi ar (n);
        for(int i=0; i<n; i++) cin >> ar[i];

        ll ans = 0;
        int a = INT_MAX;
        int b = INT_MAX;
        for(auto i: ar)
        {
            if(a > b) 
            {
                int temp = a;
                a = b;
                b = temp;
            }

            if(i <= a) a = i;
            else if(i <= b) b = i;
            else 
            {
                a = i;
                ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}