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
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++) {
            cin >> nums[i];
            pq.push(nums[i]);
        }

        int ans = INT_MIN;
        while(n > 0) {
            int temp = pq.top() * n; pq.pop(); n--;
            ans = max(ans, temp);
        }

        cout << ans << "\n";
    }

    return 0;
}