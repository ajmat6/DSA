#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int s, each, pass;
        cin >> s >> each >> pass;

        ll total = s * each;
        ll half = total / 2;

        if(pass > half) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}