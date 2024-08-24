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

        vector<int> ans;
        int teamNo = 1;
        while(n > 2) {
            ans.push_back(teamNo);
            ans.push_back(teamNo + 2);
            ans.push_back(teamNo + 1);

            n -= 3;
            teamNo += 3;
        }

        while(n != 0) {
            ans.push_back(teamNo);
            teamNo++;
            n--;
        }

        for(auto i: ans) cout << i << " ";
        cout << "\n";
    }

    return 0;
}