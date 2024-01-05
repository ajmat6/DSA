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
        int chest, key, most;
        cin >> chest >> key >> most;

        if(chest >= key) cout << chest << "\n";
        else
        {
            if(chest + most >= key) cout << key << "\n";
            else cout <<chest + (key - chest) + (key - (chest + most)) << "\n";
        }
    }

    return 0;
}