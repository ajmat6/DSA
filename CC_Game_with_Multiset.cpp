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

bool solve(vi& v, int index, int sum, vvi& dp)
{
    if(sum == 0) return true;
    if(sum < 0) return false;
    if(index == v.size())
    {
        if(sum == 0) return true;
        else return false;
    }

    if(dp[index][sum] != -1) return dp[index][sum];

    // take curr index:
    bool take = solve(v, index + 1, sum - v[index], dp);
    bool notTake = solve(v, index + 1, sum, dp);
    return dp[index][sum] =  (take || notTake);
}

bool solve2(vi& v, int b)
{
    vvi dp (v.size() + 1, vi (b + 1, 0));
    for(int i=0; i<dp.size(); i++)
    {
        dp[i][0] = 1;
    }

    for(int index=v.size()-1; index>=0; index--)
    {
        for(int sum=1; sum<=b; sum++)
        {
            bool take = false;
            if(sum - v[index] >= 0) take = dp[index + 1][sum - v[index]];
            bool notTake = dp[index + 1][sum];
            dp[index][sum] =  (take || notTake);
        }
    }

    return dp[0][b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    multiset<int> st;
    while(t--)
    {
        int a, b;
        cin >> a >> b;

        if(a == 1)
        {
            st.insert(pow(2, b));
        }  
        else
        {
            if(b == 0) cout << "YES\n";
            else
            {
                vector<int> temp (st.begin(), st.end());
                vvi dp (temp.size() + 1, vi (b + 1, -1));
                if(solve2(temp, b)) cout << "YES\n";
                else cout << "NO\n";
            }
        } 
    }

    return 0;
}