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
        vi nums(16);
        for(int i=0; i<16; i++) cin >> nums[i];

        vector<int> arr = nums;
        sort(arr.begin(), arr.end());

        unordered_map<int, int> mp;
        for(int i=0; i<16; i++) {
            int teams = i + 1;
            int count = 0;
            while(teams != 1) {
                count += 1;
                teams /= 2;
            }
            mp[arr[i]] = count;
        }

        vector<int> ans;
        for(int i=0; i<16; i++) {
            ans.push_back(mp[nums[i]]);
        }

        for(auto i: ans) cout << i << " ";
        cout << endl;
    }

    return 0;
}