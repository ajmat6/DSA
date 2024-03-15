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
        for(int i=0; i<n; i++) cin >> a[i];

        bool poss1 = true;
        int i = 0;
        while(i < n - 1)
        {
            if(abs(a[i] - a[i + 1]) > 1) 
            {
                poss1 = false;
                break;
            }
            i += 2;
        }

        if(poss1) 
        {
            cout << "YES\n";
            continue;
        }
        
        bool poss2 = true;
        i = n - 1;
        while(i > 0)
        {
            if(abs(a[i] - a[i - 1]) > 1)
            {
                poss2 = false;
                break;
            }
            i -= 2;
        } 

        if(poss1 || poss2) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}