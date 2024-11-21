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
        for(int i=0; i<n; i++) cin >> nums[i];

        int count = 0;
        for(int i=0; i<n; i++) {
            for(int k=i-100; k<=i+100; k++) {
                if(k >= 0 && k < n) {
                    int valDiff = abs(nums[i] - nums[k]);
                    int indDiff = abs(i - k);

                    int diff = valDiff - indDiff;
                    if(diff % 2 == 0 && diff / 2 >= 0) {
                        if(diff == 0) count += abs(i - k) + 1;
                        else {
                            int half = diff / 2;
                            if(min(i, k) - half >= 0) count += 1;
                            if(max(i, k) + half < n) count += 1;
                        }
                    }
                }
            }
        }
        cout << count << "\n";
    }

    return 0;
}