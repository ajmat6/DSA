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

int solve(int row, int col, vector<vector<char>>& grid, int n, vvi& dp)
{
    if(row == (n - 1) && col == (n - 1)) return 1;

    if(dp[row][col] != -1) return dp[row][col];

    int right = 0;
    int down = 0;
    if(col + 1 < n && grid[row][col + 1] != '*') right = solve(row, col + 1, grid, n, dp);
    if(row + 1 < n && grid[row + 1][col] != '*') down = solve(row + 1, col, grid, n, dp);
     
    return dp[row][col] = (right + down) % mod;
}

int solve2(vector<vector<char>>& grid, int n)
{
    vvi dp (n + 1, vi (n + 1, 0));
    dp[n-1][n-1] = 1;

    for(int row=n-1; row>=0; row--)
    {
        for(int col=n-1; col>=0; col--)
        {
            if(row == n - 1 && col == n - 1) continue;
            int right = 0;
            int down = 0;
            if(col + 1 < n && grid[row][col + 1] != '*') right = dp[row][col + 1];
            if(row + 1 < n && grid[row + 1][col] != '*') down = dp[row + 1][col];
            
            dp[row][col] = (right + down) % mod;
        }
    }

    return dp[0][0];
}

// space optimisation:
int solve3(vector<vector<char>>& grid, int n)
{
    vi curr (n + 1, 0);
    vi next (n + 1, 0);
    curr[n-1] = 1;
    next[n-1] = 1;

    for(int row=n-1; row>=0; row--)
    {
        for(int col=n-1; col>=0; col--)
        {
            if(row == n - 1 && col == n - 1) continue;
            int right = 0;
            int down = 0;
            if(col + 1 < n && grid[row][col + 1] != '*') right = curr[col + 1];
            if(row + 1 < n && grid[row + 1][col] != '*') down = next[col];
            
            curr[col] = (right + down) % mod;
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

    int n; 
    cin >> n;
    vector<vector<char>> grid (n, vector<char> (n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> grid[i][j];
        }
    }

    // vvi dp (n + 1, vi (n + 1, -1));
    // if(grid[0][0] != '*' && grid[n-1][n-1] != '*') cout << solve(0, 0, grid, n, dp);
    // if(grid[0][0] != '*' && grid[n-1][n-1] != '*') cout << solve2(grid, n);
    if(grid[0][0] != '*' && grid[n-1][n-1] != '*') cout << solve3(grid, n);
    else cout << "0";

    return 0;
}