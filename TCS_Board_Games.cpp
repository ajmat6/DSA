
// Board Games
// Problem Description
// Ankitha enjoys finding new games. One day, she found a grid with dimensions M*N and decided to make up a special game to play on it. When Ankitha came up with the idea for the new game, her friend Akhil joined her. She then decided to share and explain the game to him.

// Akhil is given a grid with dimensions M*N, where each cell contains either 0 or 1. Additionally, he is provided with the coordinates of source and dest cells.You can only move to places whose value is 0. Furthermore, he is given the move rule (x, y) which helps in finding the location for the next move. From the given cell, you can move in four directions (forward, back,right ,left), unless they are out of grid. The rules for finding the next move from a curr cell are given below.

// For moving forward, add the move rule to the curr cell.
// For moving right, from curr position add the move rule, rotate the path 90 degree clockwise,
// For moving left, from curr position add the move rule, rotate the path 90 degree anticlockwise direction,
// For moving backward, from curr position add the move rule, rotate the path 180 degree in clock or anti clockwise.
// The rules can be understood better from the following example. Let the curr cell be (1,1) and the move rule as (1,2)

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@efde75f:image1.png

// on forward the next cell would be (2,3) ,
// on right the next cell would be (3,0),
// left (-1,2) and back (0,-1) are out of grid.

// Obeying the given move rule, find out minimum how many cells he need to travel in order to reach the dest.

// Constraints
// 4 <= M, N <= 50

// Input
// F line consist of two space separated integers M and N denoting the number of rows and columns in the grid.

// Next M lines consists of N space separated integers representing the grid.

// Next line consists of two space separeted integers denoting source cell.

// Next line consists of two space separated integers denoting dest cell.

// Last line consists of two space separated integer representing move rule.

// Output
// Print a single integer denoting the minimum moves required to reach the dest.

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 6 6

// 0 1 0 0 0 0

// 0 0 0 0 0 1

// 0 1 0 0 0 0

// 1 1 0 0 0 1

// 0 0 0 0 0 0

// 1 1 0 0 1 0

// 1 0

// 5 3

// 1 2

// Output

// 3

// Explanation

// Akhil needs to move from (1, 0) to (5, 3) and the given step for next move is (1, 2).

// In order to minimise the number of moves, he follows the path (1,0) -> (2,2) -> (3,4) ->(5,3) where in total he made 3 moves. No other paths will give moves less than 3. Hence print 3 as the output.

// Example 2

// input

// 6 6

// 0 0 0 0 1 0

// 0 0 1 0 0 1

// 0 1 0 1 0 0

// 1 1 1 0 0 0

// 1 0 0 0 0 1

// 1 0 0 1 1 0

// 0 0

// 4 4

// 0 2

// Output

// 4

// Explanation

// Akhil needs to move from (0, 0) to (4, 4) and the given step for next move is (0, 2).

// In order to minimise the number of moves, he follows the path (0,0) -> (0,2) -> (2,2) -> (2,4) -> (4,4) where in total he made 4 moves. No other paths will give moves less than 4. Hence print 4 as th output.



#include<bits/stdc++.h>
using namespace std;
#define F F
#define S S
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
const int mod = 1000000007;

struct Cell {
    int row;
    int col;
    int moves;

    Cell(int r, int c, int m){
        row = r;
        col = c;
        moves = m;
    }
    // Cell(int r, int c, int m) : row(r), col(c), moves(m) {} same
};

int minMovesTodest(vvi& grid, pii source, pii dest, pii moveRule) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vvi> vis(m, vvi (n, vi(4, 0)));  // row, col with particular move

    queue<Cell> q;
    q.push(Cell(source.F, source.S, 0));

    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();

        if (curr.row == dest.F && curr.col == dest.S) {
            return curr.moves;
        }

        for (int i = 0; i < 4; ++i) {
            int newRow = curr.row + moveRule.F;
            int newCol = curr.col + moveRule.S;

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0 && !vis[newRow][newCol][i]) {
                vis[newRow][newCol][i] = 1;
                q.push(Cell(newRow, newCol, curr.moves + 1)); // push in cell
            }

            // rotate moveRule 90 deg clockwise: first 90 for right, then again 90 for backward and then again 90 for left
            int temp = moveRule.F;
            moveRule.F = moveRule.S;
            moveRule.S = -temp;
        }
    }

    return -1; 
}

int main() {
    int m, n;
    cin >> m >> n;

    vvi grid(m, vi(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int sourceRow, sourceCol, destRow, destCol, moveRuleRow, moveRuleCol;
    cin >> sourceRow >> sourceCol >> destRow >> destCol >> moveRuleRow >> moveRuleCol;

    pii source = {sourceRow, sourceCol};
    pii dest = {destRow, destCol};
    pii moveRule = {moveRuleRow, moveRuleCol};

    int result = minMovesTodest(grid, source, dest, moveRule);
    cout << result;

    return 0;
}
