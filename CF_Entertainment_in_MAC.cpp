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

        int m = s.size();
        bool first = true;
        int low = 0;
        int high = m - 1;

        while(s[low] == s[high] && low < high) {
            low++; high--;
        }

        string rev = "";
        for(int i=m-1; i>=0; i--) rev += s[i];
        
        if(s[low] <= s[high]) {
            if(n % 2 == 0) cout << s << "\n";
            else cout << s + rev << "\n";
        }

        else {
            if(n % 2 == 0) cout << rev + s << "\n";
            else cout << rev << "\n";
        }

    }


    return 0;
}