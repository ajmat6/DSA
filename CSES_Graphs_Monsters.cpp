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
int xIndex = -1;
int yIndex = -1;
int startX = -1;
int startY = -1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, w;
    cin >> h >> w;

    vector<vector<char>> mat (h, vector<char> (w));
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            cin >> mat[i][j];
        }
    }

    vvi dist (h, vi (w, INT_MAX));
    vvi vis (h, vi (w, 0));
    queue<pair<int, int>> q;

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(mat[i][j] == 'M')
            {
                q.push({i, j});
                dist[i][j] = 0;
                vis[i][j] = 1;
            }

            else if(mat[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
        }
    }

    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        // checking all possible four directions:
        for(int i=0; i<4; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if(newRow >=0 && newRow < h && newCol >= 0 && newCol < w && mat[newRow][newCol] == '.' && vis[newRow][newCol] == 0 && dist[row][col] + 1 < dist[newRow][newCol])
            {
                q.push({newRow, newCol});
                vis[newRow][newCol] = 1;
                dist[newRow][newCol] = 1 + dist[row][col];
            }
        }
    }

    vvi viss (h, vi (w, 0));
    q.push({startX, startY});
    viss[startX][startY] = 1;
    dist[startX][startY] = 0;

    map<pair<int, int>, pair<int, int>> mp;
    mp[{startX, startY}] = {-1 , -1};

    string result = "";

    bool found = false;
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            int row = q.front().F;
            int col = q.front().S;
            q.pop();

            if(row == 0 || col == 0 || row == (h - 1) || col == (w - 1))
            {
                found = true;
                xIndex = row;
                yIndex = col;
                break;
            }

            for(int i=0; i<4; i++)
            {
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if(newRow >= 0 && newRow < h && newCol >= 0 && newCol < w && mat[newRow][newCol] == '.' &&  viss[newRow][newCol] == 0 && 1 + dist[row][col] < dist[newRow][newCol])
                {
                    if(newRow == 0 || newCol == 0 || newRow == (h - 1) || newCol == (w - 1))
                    {
                        found = true;
                        mp[{newRow, newCol}] = {row, col};
                        xIndex = newRow;
                        yIndex = newCol;  
                        break;
                    }

                    else
                    {
                        q.push({newRow, newCol});
                        viss[newRow][newCol] = 1;
                        dist[newRow][newCol] = 1 + dist[row][col];
                        mp[{newRow, newCol}] = {row, col};
                    }
                }
            }

            if(found) break;
        }

        if(found) break;
    }

    if(!found) cout << "NO";
    else 
    {
        bool com = false;
        while(1)
        {
            if(xIndex == startX && yIndex == startY) break;
            int row = mp[{xIndex, yIndex}].first;
            int col = mp[{xIndex, yIndex}].second;

            for(int i=0; i<4; i++)
            {
                int newRow = xIndex + dx[i];
                int newCol = yIndex + dy[i];

                if(newRow == row && newCol == col)
                {
                    if(i == 0) result.push_back('U');
                    else if(i == 1) result.push_back('R');
                    else if(i == 2) result.push_back('D');
                    else if(i == 3) result.push_back('L');

                    xIndex = newRow;
                    yIndex = newCol;

                    if(newRow == startX && newCol == startY) com = true;
                    break;
                }
            }
            if(com) break;
        }

        for(int i=0; i<result.size(); i++)
        {
            if(result[i] == 'U') result[i] = 'D';
            else if(result[i] == 'D') result[i] = 'U';
            else if(result[i] == 'R') result[i] = 'L';
            else if(result[i] == 'L') result[i] = 'R';
        }
        reverse(result.begin(), result.end());
        cout << "YES\n" << result.size() << "\n" << result;
    }
    

    return 0;
}