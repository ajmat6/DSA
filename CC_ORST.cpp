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
        ll n, m;
        cin >> n >> m;

        vll A (n);
        vll B (m);
        for(int i=0; i<n; i++) cin >> A[i];

        ll maxi = LLONG_MIN;
        for(int i=0; i<m; i++)
        {
            cin >> B[i];
            maxi = max(maxi, B[i]);
        }

        ll index = n - maxi;
        vll temp (maxi);
        int j = 0;
        for(int i=index; i<n; i++)
        {
            temp[j] = A[i];
            j++;
        }

        sort(temp.begin(), temp.end());
        j = 0;
        for(int i=index; i<n; i++)
        {
            A[i] = temp[j]; 
            j++;
        }

        for(int i=0; i<n; i++) cout << A[i] << " ";
        cout << "\n";
    }

    return 0;
}