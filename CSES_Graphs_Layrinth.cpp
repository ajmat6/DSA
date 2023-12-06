#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
int dx[4] = {-1, 0, 1, 0}; // up left down right
int dy[4] = {0, 1, 0, -1};
string result = "";
int ans = INT_MAX;

void dfs(vector<vector<char>>& mat, int h, int w, int row, int col, vector<vector<int>>& vis, int count, string temp)
{
    if(mat[row][col] == 'B')
    {
        if(count < ans)
        {
            ans = count;
            result = temp;
        }
        return;
    }

    vis[row][col] = 1;
    for(int i=0; i<4; i++)
    {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        if(newRow >= 0 && newRow < h && newCol >= 0 && newCol < w && mat[newRow][newCol] != '#' && vis[newRow][newCol] == 0)
        {
            if(i == 0) dfs(mat, h, w, newRow, newCol, vis, count + 1, temp + "U");
            else if(i == 1) dfs(mat, h, w, newRow, newCol, vis, count + 1, temp + "R");
            else if(i == 2) dfs(mat, h, w, newRow, newCol, vis, count + 1, temp + "D");
            else if(i == 3) dfs(mat, h, w, newRow, newCol, vis, count + 1, temp + "L");
        }
    }
    vis[row][col] = 0;
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

    vector<vector<int>> vis (h, vector<int> (w));
    queue<pair<int, int>> q;

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(mat[i][j] == 'A')
            {
                dfs(mat, h, w, i, j, vis, 0, "");
                break;
            }
        }
    }
    
    if(ans == INT_MAX) cout << "NO";
    else 
    {
        cout << "YES\n" << ans << "\n" << result;
    }

    return 0;
}