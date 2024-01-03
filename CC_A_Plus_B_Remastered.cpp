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
        int n;
        cin >> n;

        vector<int> a (n);
        vector<int> b (n);

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            sum += a[i];
            mp1[a[i]]++;
        }
        for(int i=0; i<n; i++)
        {
            cin >> b[i];
            sum += b[i];
            mp2[b[i]]++;
        }

        int oneTerm = sum / n;
        int rem = sum % n;

        if(rem != 0)
        {
            cout << "-1\n";
            continue;
        }

        else
        {
            bool complete = true;
            vi a1;
            vi b1;
            for(auto i: mp1)
            {
                int value = i.first;
                int rem = oneTerm - value;
                if(rem <= 0)
                {
                    cout << "-1\n";
                    break;
                }

                for(int j=0; j<i.second; j++)
                {
                    bool found = false;
                    for(auto k: mp2)
                    {
                        if(k.first == rem)
                        {
                            mp2[k.first]--;
                            found = true;
                            a1.pb(value);
                            b1.pb(rem);
                            break;
                        }
                    }

                    if(!found)
                    {
                        cout << "-1\n";
                        complete = false;
                        break;
                    }
                }

                if(!complete)
                {
                    break;
                }
            }

            if(complete)
            {
                for(auto i: a1) cout << i << " ";
                cout << "\n";
                for(auto i: b1) cout << i << " ";
            }
        }
    }

    return 0;
}