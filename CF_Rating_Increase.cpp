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
        string ab;
        cin >> ab;

        string a = "";
        string b = "";

        a += ab[0];
        int i = 1;
        while(true)
        {
            if(ab[i] != '0') break;
            i++;
        }

        bool found = false;
        for(int j=i; j<ab.size(); j++)
        {
            a = ab.substr(0, j);
            b = ab.substr(j, ab.size() - j);

            if(stoi(a) < stoi(b))
            {
                found = true;
                break;
            }
        }

        if(!found) cout << "-1\n";
        else cout << stoi(a) << " " << stoi(b) << "\n";
    }

    return 0;
}