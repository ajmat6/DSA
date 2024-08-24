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

        int index1 = 0, index2 = n - 1;
        while(index1 < n && s[index1] == '0') index1++;
        while(index2 >= 0 && s[index2] == '0') index2--;

        if(index1 == n && index2 < 0) cout << n << "\n";
        else {
            int total = index1 + (n - index2 - 1);
            cout << total << "\n";
        }
    }

    return 0;
}