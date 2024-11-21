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
        
        vll nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        
        sort(nums.begin(), nums.end());
        vector<pll> pairs;
        for(int i=1; i<n; i++) {
            ll currMin = nums[i] - nums[i - 1] + 1;
            ll currMax = nums[i] + nums[i - 1] - 1;

            pairs.push_back({currMin, currMax});
        }
        
        ll total = 0;
        sort(pairs.begin(), pairs.end());
        
        ll prev = INT_MIN;
        for(auto i: pairs) {
            if(i.second > prev) {
                if(i.first > prev) total += (i.second - i.first + 1);
                else total += (i.second - prev);
                prev = i.second;
            }
        }

        cout << total << "\n";
    }

    return 0;
}