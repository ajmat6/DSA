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

        string a, b;
        cin >> a;
        cin >> b;

        vi ans (n);
        for(int i=0; i<n; i++) {
            int first = a[i] - 'A';
            int second = b[i] - 'A';

            if(first < second) {
                int diff = second - first;
                if(diff % 3 == 0) ans[i] = diff / 3;
                else {
                    diff += 26;
                    if(diff % 3 == 0) ans[i] = diff / 3;
                    else {
                        diff += 26;
                        ans[i] = diff / 3;
                    }
                }
            }

            else if(first > second) {
                int diff = 26 - first + second;
                if(diff % 3 == 0) ans[i] = diff / 3;
                else {
                    diff += 26;
                    if(diff % 3 == 0) ans[i] = diff / 3;
                    else {
                        diff += 26;
                        ans[i] = diff / 3;
                    }
                }
            }

            else ans[i] = 0;
        }

        for(int i=0; i<n; i++) cout << ans[i] << " ";
        cout << "\n";
    }


    return 0;
}