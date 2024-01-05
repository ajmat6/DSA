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

    while(t--)
    {
        int b, k;
        cin >> b >> k;

        vi temp (b);
        for(int i=0; i<b; i++) cin >> temp[i];

        ll pro = 1;
        for(auto i: temp) pro *= i;

        ll div = 2023 / pro;

        // check if div is int or not:
        if(div * pro != 2023) cout << "NO\n";
        else 
        {
            cout << "YES\n";
            cout << div << " ";
            k--;

            while(k != 0)
            {
                cout << "1" << " ";
                k--;
            }
            cout << "\n";
        }
    }

    return 0;
}