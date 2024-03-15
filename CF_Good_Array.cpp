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

    ll n;
    cin >> n;

    vi nums (n);
    ll total = 0; // total sum
    unordered_map<ll, ll> mp;
    for(ll i=0; i<n; i++) {
        cin >> nums[i];
        total += nums[i];
        mp[nums[i]]++;
    }

    vi res;
    for(ll i=0; i<n; i++) {
        ll sum = total - nums[i];
        if(sum % 2 == 0) {
            ll element = sum / 2;
            if(mp.find(element) != mp.end() && (element != nums[i] || mp[element] > 1)) {
                res.pb(i);
            }
        }
    }

    cout << res.size() << "\n";
    for(ll i=0; i<res.size(); i++) cout << res[i] + 1 << " ";

    return 0;
}