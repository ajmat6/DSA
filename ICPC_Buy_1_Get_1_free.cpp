#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef priority_queue<int> maxHeap;
typedef priority_queue<int, vector<int>, greater<int>> minHeap;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
const int mod = 1000000007;

void solve() {
    ll n, k;
    cin >> n >> k;

    vll nums (n);
    for(int i=0; i<n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());
    vll sum (n);
    vll freeCount(n);
    sum[0] = nums[0];
    freeCount[0] = nums[0];
    for(int i=1; i<n; i++) {
        sum[i] = nums[i] + sum[i - 1];
        if(i - k - 1 >= 0) freeCount[i] = nums[i] + freeCount[i -  k - 1];
        else freeCount[i] = nums[i];
    }

    vll ans (n);
    for(int i=0; i<n; i++) {
        if(i < k) ans[i] = sum[i];
        else {
            ans[i] = sum[i];
            ans[i] -= freeCount[i - k];
        }
    }

    for(int i=0; i<n; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}