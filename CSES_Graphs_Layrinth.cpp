#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
int dx[4] = {-1, 0, 1, 0}; // up right down left
int dy[4] = {0, 1, 0, -1};
string result = "L";
int ans = 0;
int xIndex = -1;
int yIndex = -1;
int startX = -1;
int startY = -1;

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

    queue<pair<int, int>> q;
    vector<vector<int>> vis (h, vector<int> (w));
    map<pair<int, int>, pair<int, int>> mp;

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(mat[i][j] == 'A')
            {
                q.push({i, j});
                vis[i][j] = 1;
                startX = i;
                startY = j;
                break;
            }
        }
    }

    bool found = false;
    while(!q.empty())
    {
        int size = q.size();
        for(int j=0; j<size; j++)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int newRow = row + dx[i];
                int newCol = col + dy[i];


                if(newRow >= 0 && newRow < h && newCol >= 0 && newCol < w && mat[newRow][newCol] != '#' && vis[newRow][newCol] == 0)
                {
                    if(mat[newRow][newCol] == 'B')
                    {
                        mp[{newRow, newCol}] = {row, col};
                        xIndex = newRow;
                        yIndex = newCol;
                        found = true;
                        break;
                    }

                    q.push({newRow, newCol});
                    vis[newRow][newCol] = 1;
                    mp[{newRow, newCol}] = {row, col};
                }
            }
        }
        ans++;
        if(found) break;
    }
    
    if(!found) cout << "NO";
    else 
    {
        bool com = false;
        while(1)
        {
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
        result = result.substr(0, result.size() - 1);
        cout << "YES\n" << ans << "\n" << result;
    }

    return 0;
}

