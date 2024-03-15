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

        vi a (n);
        vi b (n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];

        // check for every index:
        bool poss = true;
        for(int i=0; i<n; i++)
        {
            bool ok = 0;
            // in left side:
            for(int j=i; j>=0; j--)
            {
                if(a[j] == b[i])
                {
                    ok = 1;
                    break;
                }

                else if(a[j] > b[i] || b[j] < b[i]) break;
            }

            if(ok) continue; // if found in right side without any error don't check for right side:

            // in right side:
            for(int j=i; j<n; j++)
            {
                if(a[j] == b[i])
                {
                    ok = 1;
                    break;
                }

                else if(a[j] > b[i] || b[j] < b[i]) break;
            }

            if(!ok)
            {
                poss = false;
                break;
            }
        }

        if(poss) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}