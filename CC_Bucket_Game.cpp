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

        vll nums (n);
        for(int i=0; i<n; i++) cin >> nums[i];

        int count = 0;
        for(auto i: nums) {
            if(i == 1) count++;
        }

        ll alice = 0; ll bob = 0;
        if(count % 2 == 0) {
            alice = count / 2;
            bob = alice;
        }
        else {
            alice = count / 2 + 1;
            bob = alice - 1;
        }

        ll total = 0;
        for(auto i: nums) {
            if(i > 2) total += i - 2;
        }

        if(total % 2 == 0) bob += 1;
        else alice += 1;

        if(alice > bob) cout << "Alice\n";
        else if(bob > alice) cout << "Bob\n";
        else cout << "Draw\n";
    }

    return 0;
}