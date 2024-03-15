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
        sort(temp.begin(), temp.end());
        
        int total = 0;
        total += temp[0] + temp[1];
        for(int i=2; i<n; i++) total += temp[i] + temp[i];
        cout << total << "\n";
    }

    return 0;
}