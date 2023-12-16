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

// int solve(string& a, string& b, int index1, int index2, vvi& dp)
// {
//     if(index1 == a.size() && index2 == b.size()) return 0;
//     if(index1 == a.size() && index2 != b.size()) return b.size() - index2;
//     if(index1 != a.size() && index2 == b.size()) return a.size() - index1;

//     if(dp[index1][index2] != -1) return dp[index1][index2];

//     int ans = INT_MAX;
//     if(a[index1] == b[index2]) ans = solve(a, b, index1 + 1, index2 + 1, dp);
//     else
//     {
//         // add that characters:
//         ans = min(ans, 1 + solve(a, b, index1, index2 + 1, dp));

//         // remove character:
//         ans = min(ans, 1 + solve(a, b, index1 + 1, index2, dp));

//         // replace character:
//         ans = min(ans, 1 + solve(a, b, index1 + 1, index2 + 1, dp));
//     }

//     return dp[index1][index2] = ans;
// }

int solve2(string& a, string& b)
{
    int n = a.size();
    int m = b.size();

    vvi dp (n + 1, vi (m + 1, 0));

    for(int i=0; i<m; i++)
    {
        dp[n][i] = m - i;
    }

    for(int j=0; j<n; j++)
    {
        dp[j][m] = n - j;
    }

    for(int index1=n-1; index1>=0; index1--)
    {
        for(int index2=m-1; index2>=0; index2--)
        {
            int ans = INT_MAX;
            if(a[index1] == b[index2]) ans = dp[index1 + 1][index2 + 1];
            else
            {
                // add that characters:
                ans = min(ans, 1 + dp[index1][index2 + 1]);

                // remove character:
                ans = min(ans, 1 + dp[index1 + 1][index2]);

                // replace character:
                ans = min(ans, 1 + dp[index1 + 1][index2 + 1]);
            }

            dp[index1][index2] = ans;
        }
    }

    return dp[0][0];
}

int solve3(string& a, string& b)
{
    int n = a.size();
    int m = b.size();

    vi curr (m + 1, 0);
    vi next (m + 1, 0);

    for(int i=0; i<m; i++)
    {
        next[i] = m - i;
    }


    for(int index1=n-1; index1>=0; index1--)
    {
        curr[m] = n - (index1);
        for(int index2=m-1; index2>=0; index2--)
        {
            int ans = INT_MAX;
            if(a[index1] == b[index2]) ans = next[index2 + 1];
            else
            {
                // add that characters:
                ans = min(ans, 1 + curr[index2 + 1]);

                // remove character:
                ans = min(ans, 1 + next[index2]);

                // replace character:
                ans = min(ans, 1 + next[index2 + 1]);
            }

            curr[index2] = ans;
        }
        next = curr;
    }

    return curr[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a = "";
    string b = "";

    cin >> a;
    cin >> b;

    // vvi dp (a.size() + 1, vi (b.size() + 1, -1));
    // cout << solve(a, b, 0, 0, dp);    
    // cout << solve2(a, b);    
    cout << solve3(a, b);    

    return 0;
}