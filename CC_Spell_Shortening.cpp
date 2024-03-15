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

        string s;
        cin >> s;

        // char largest = s[0];
        int index;
        // int larIndex = 0;
        bool found = false;
        for(int i=0; i<n-1; i++) {
            if(s[i] > s[i+1]) {
                found = true;
                index = i;
                break;
            }

            // else {
            //     if(s[i] >= largest) {
            //         largest = s[i];
            //         larIndex = i;
            //     }
            // }
        }

        if(found) cout << s.substr(0, index) + s.substr(index + 1, n - (index + 1)) << "\n";
        else cout << s.substr(0, n - 1) << "\n";
    }

    return 0;
}