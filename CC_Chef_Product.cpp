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

        ll sum = 1;
        ll odd = 3;
        ll times = 1;
        while(sum < n)
        {
            sum += odd;
            odd += 2;
            if(sum < n) times++;
            else break;
        }        

        if(n % 2 == 1 && times % 2 == 1) cout << times / 2 + 1;
        else cout << times / 2 << "\n";
    }

    return 0;
}