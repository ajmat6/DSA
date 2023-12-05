#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(vector<vector<char>>& mat, int h, int w, int row, int col, vector<vector<int>>& vis)
{
    vis[row][col] = 1;
    
    for(int i=0; i<4; i++)
    {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        if(newRow >= 0 && newRow < h && newCol >= 0 && newCol < w && mat[newRow][newCol] == '.' && vis[newRow][newCol] == 0)
        {
            dfs(mat, h, w, newRow, newCol, vis);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    cin >> h >> w;

    vector<vector<char>> mat (h, vector<char> (w));
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++) cin >> mat[i][j];
    }

    int ans = 0;
    vector<vector<int>> vis (h, vector<int> (w));
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(mat[i][j] == '.' && vis[i][j] == 0)
            {
                dfs(mat, h, w, i, j, vis);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}