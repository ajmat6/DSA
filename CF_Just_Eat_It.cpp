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

        vi nums (n);
        ll total = 0;
        for(int i=0; i<n; i++) {
            cin >> nums[i]; total += nums[i];
        }

        vll temp (n); temp[0] = nums[0];
        for(int i=1; i<n; i++) temp[i] = nums[i] + temp[i - 1]; // find prefix sum

        bool poss = true; 
        ll maxSum = INT_MIN;
        for(int i=0; i<n; i++) {
            maxSum = max(maxSum, temp[i]);
            if(temp[i] <= 0 || (maxSum >= total && i != n - 1)) {
                poss = false;
                break;
            }
        }

        if(!poss) cout << "NO\n";
        else cout <<"YES\n";
    }

    return 0;
}