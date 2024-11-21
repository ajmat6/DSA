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
        ll n, k;
        cin >> n >> k;

        vll nums (n);
        for(int i=0; i<n; i++) cin >> nums[i];

        bool poss = true;
        for(auto i: nums) {
            if(i != k) {
                poss = false;
            }
        }
        
        if(poss) {
            cout << "0\n";
            continue;
        }
        
        // finding inbetween range where elements are not k: checking for 1 case:
        int low = -1;
        int high = -1;
        for(int i=0; i<n; i++) {
            if(nums[i] != k) {
                if(low == -1) low = i;
                high = i;
            }
        }

        bool gcd = true;
        bool xorr = true;
        int x = nums[low] ^ k;
        for(int i=low; i<=high; i++) {
            if(nums[i] % k != 0) gcd = false;
            if((nums[i] ^ x) != k) xorr = false;
        }
        
        if(gcd || xorr || low == high) cout << "1\n";
        else cout << "2\n";
    }

    return 0;
}