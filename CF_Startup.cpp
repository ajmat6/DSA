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
   int n, k;
   cin >> n >> k;

   unordered_map<int, int> mp;
   for(int i=0; i<k; i++) {
        int b, c;
        cin >> b >> c;
        mp[b] += c;
   }

   vi nums;
   for(auto i: mp) nums.push_back(i.second);
   sort(nums.begin(), nums.end(), greater<int>());

    int total = 0;
    int mapSize = mp.size();
   for(int i=0; i<min(n, mapSize); i++) {
        total += nums[i];
   }
   cout << total << endl;
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