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
    int n, x; cin >> n >> x;

    vi A(n), B(n);
    for(int i=0; i<n; i++) cin >> A[i];
    for(int i=0; i<n; i++) cin >> B[i];

    vi count;
    int wins = 0;
    for(int i=0; i<n; i++) {
        if(A[i] > B[i]) wins++;
        else {
            count.push_back(B[i] - A[i] + 1);
        }
    }
    if(wins > n / 2) cout << "YES\n";
    else {
        sort(count.begin(), count.end());
        for(auto i: count) {
            if(i <= x) {
                x -= i;
                wins++;
            }
            else break;
        }

        if(wins > n / 2) cout << "YES\n";
        else cout << "NO\n";
    }
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