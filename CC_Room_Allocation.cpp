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

    while(t--) {
        int n;
        cin >> n;

        vi temp (n);
        for(int i=0; i<n; i++) cin >> temp[i];

        int total = 0;
        for(int i=0; i<n; i++) {
            if(temp[i] % 2 == 0) total += temp[i] / 2;
            else total += temp[i] / 2 + 1;
        }

        cout << total << "\n";
    }

    return 0;
}