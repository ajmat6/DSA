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

void findAll(vll& gift, ll index, ll sum, set<ll>& temp)
{
    if(index == gift.size())
    {
        temp.insert(sum);
        return;
    }

    findAll(gift, index + 1, sum + gift[index], temp);
    findAll(gift, index + 1, sum, temp);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int n, hr, save;
        cin >> n >> hr >> save;

        vll gift (n);
        ll sum = 0;
        for(ll i=0; i<n; i++)
        {
            cin >> gift[i];
            sum += gift[i];
        } 

        ll money = 0;
        ll ans = 0;
        while(money < save)
        {
            money += hr;
            ans += 1;
        }

        if(money == save)
        {
            cout << ans << "\n";
        }

        else 
        {
            set<ll> temp;
            ll left = money - save;
            findAll(gift, 0, 0, temp);

            if(temp.find(left) != temp.end())
            {
                cout << ans << "\n";
            }

            else
            {
                while(true)
                {
                    ans += 1;
                    left += hr;

                    if(temp.find(left) != temp.end())
                    {
                        cout << ans << "\n";
                        break;
                    }

                    else if(left > sum)
                    {
                        cout << "-1\n";
                        break;
                    }
                }
            }
        }
    }

    return 0;
}