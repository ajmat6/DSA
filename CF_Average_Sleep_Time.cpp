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

    int n, k;
    cin >> n >> k;

    vi nums (n);
    for(int i=0; i<n; i++) cin >> nums[i];

    long double total = 0.0;
    long double sum = 0.0;
    for(int i=0; i<k; i++) sum += nums[i];
    total = sum;

    int low = 0;
    int high = k;

    while(high < n) {
        sum -= nums[low];
        sum += nums[high];
        total += sum;
        low++;
        high++;
    }

    cout << setprecision(10) << total / (n - k + 1);

    return 0;
}