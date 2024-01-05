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

int solve(vi& a, vi& b, int n, int k, int currQuest, int prev, vvi& dp)
{
    if(k == 0) return 0;

    if(dp[k][currQuest] != -1) return dp[k][currQuest];

    // two options to take currQuest score else previous quests max score:
    int currTake = 0;
    if(currQuest < n)
    {
        int previous = prev;
        if(b[currQuest] > prev) prev = b[currQuest];
        currTake = a[currQuest] + solve(a, b, n, k-1, currQuest + 1, prev, dp);
        prev = previous;
    }

    int prevTake = prev + solve(a, b, n, k-1, currQuest, prev, dp);
    return dp[k][currQuest] = max(currTake, prevTake);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a (n);
        vector<int> b (n);

        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];

        // find prefix sum of the array:
        vector<int> prefix (n);
        prefix[0] =  a[0];
        for(int i=1; i<n; i++) prefix[i] = prefix[i-1] + a[i];

        int ans = INT_MIN;
        int maxi = b[0];
        for(int i=0; i<min(n, k); i++)
        {
            ans = max(ans, prefix[i] + ((k - (i + 1)) * maxi));
            if(i + 1 < n) maxi =  max(maxi, b[i+1]);
        }

        cout << ans << "\n";
    }
    return 0;
}