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
        string town;
        cin >> town;

        bool made = true;
        for(int i=0; i<town.size(); i++)
        {
            if(i == 0 || i == 2 || i == 4 || i == 6 || i == 7)
            {
                if(town[i] == 'A' || town[i] == 'E' || town[i] == 'I' || town[i] == 'O' || town[i] == 'U')
                {
                    made = false;
                    break;
                }
            }
            else
            {
                if(town[i] == 'A' || town[i] == 'E' || town[i] == 'I' || town[i] == 'O' || town[i] == 'U') continue;
                else
                {
                    made = false;
                    break;
                }
            }
        }

        if(made) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}