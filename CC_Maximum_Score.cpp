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

        vi v (n);
        for(int i=0; i<n; i++) cin >> v[i];

        int i = 0;
        int count = 0;
        while(i < n - 1)
        {
            if((v[i] == 0 && v[i + 1] == 1) || (v[i] == 1 && v[i] == 0))
            {
                count++;
                i += 2;
            }
            else i++;
        } 

        if(count <= n / 2) cout << count << "\n";
        else cout << n / 2 << "\n";
    }

    return 0;
}