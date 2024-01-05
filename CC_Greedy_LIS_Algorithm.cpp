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

        if(x == 0)
        {
            for(int i=1; i<=n; i++) cout << i << " ";
            cout << "\n";
        }

        else if(x == n - 2)
        {
            cout << n << " ";
            for(int i=1; i<n; i++) cout << i << " ";
            cout <<"\n";
        }

        else if(x <= (n - 3))
        {
            cout << "1 " << x + 3 << " ";
            for(int i=2; i<(x + 3); i++) cout << i << " ";
            for(int i=x+4; i<=n; i++) cout << i << " ";
            cout << "\n";
        }
        
        else cout << "-1\n";
    }

    return 0;
}