// raffic Flow
// Problem Description
// A traffic flow grid is a conceptual representation used in transportation planning and traffic engineering to model and analyze the movement of vehicles through a network of intersections in the city called as junctions. A traffic flow grid is akin to a matrix, with rows and columns denoting various junctions, and matrix cell values symbolizing the traffic flow in that junction. In the era of screens and swipes, traffic's stage can be seen on mobile!

// Srihan finds himself caught in traffic on his way to the workplace. To speed up his journey, he opts to assess the traffic flow grid and chooses a quicker route. He currently resides at coordinates (i, j), and his office is located at coordinates (a, b) in the traffic grid. Given a rule that from a given junction, he can only go to right or down junction (junction is a cell, in terms of matrix). Could you assist him in finding a faster route to reach his workplace?

// Constraints
// Note that the provided positions in the input are indexed starting from 1, where left top is (1, 1).

// 1 <= n, m <= 100

// 0 <= traffic flow <= 10^3

// Input
// First line consists of two space separated integers n, m denoting the number of rows and columns in the traffic grid.

// Next n lines consists of m space separated integers denoting the traffic flow. The value at i, j indicates the traffic flow at junction i and j.

// Line n+2 consists of two space separated integers denoting the coordinates of Srihan's current position.

// Line n+3 consists of two separated integers denoting the coordinates of Srihan's workplace.

// Output
// Single integer denoting the the minimum traffic flow Srihan must navigate to reach his workplace. In case there is no path from his current location to workplace, print "-1".

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 4 4

// 3 1 9 2

// 12 3 10 1

// 11 10 14 2

// 5 4 3 7

// 1 2

// 4 4

// Output

// 22

// Explanation

// Srihan will choose the path - (1,2) -> (1,3) -> (1,4) -> (2,4) -> (3,4) -> (4,4)

// The total traffic flow Srihan navigated is 1 + 9 + 2 + 1 + 2 + 7 = 22 which is the minimum possible.

// Example 2

// Input

// 3 3

// 6 9 1

// 4 7 3

// 5 0 2

// 1 1

// 3 3

// Output

// 17

// Explanation

// Srihan will choose the path - (1,1) -> (2,1) -> (2,2) -> (3,2) -> (3,3)

// The total traffic flow Srihan navigated is 6 + 4 + 5 + 0 + 2 = 17 which is the minimum possible.



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
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
const int mod = 1000000007;
const int INF = 1e9; 

int solve(vvi& traffic, vvi& dp, int i, int j, int n, int m, pii start) {
    if (i < 0 || j < 0) {
        return INF;
    }

    if (dp[i][j] != INF) {
        return dp[i][j];
    }

    if (i == start.F - 1 && j == start.S - 1) {
        return traffic[i][j];
    }

    int fromTop = solve(traffic, dp, i - 1, j, n, m, start);
    int fromLeft = solve(traffic, dp, i, j - 1, n, m, start);

    dp[i][j] = traffic[i][j] + min(fromTop, fromLeft);
    return dp[i][j];
}

int minTrafficFlow(int n, int m, vvi& traffic, pii start, pii dest) {
    vvi dp(n, vi(m, INF));
    dp[start.F - 1][start.S - 1] = traffic[start.F - 1][start.S - 1];

    int result = solve(traffic, dp, dest.first - 1, dest.second - 1, n, m, start);

    if (result == INF) {
        return -1; 
    }

    return result;
}

// tabulation
// int minTrafficFlow(int n, int m, vvi& traffic, pii start, pii dest) {
//     vvi dp(n, vi(m, INF));
//     dp[start.F - 1][start.S - 1] = traffic[start.F - 1][start.S - 1];

//     for (int i = start.F - 1; i < n; ++i) {
//         for (int j = start.S - 1; j < m; ++j) {
//             if (i > 0) {
//                 dp[i][j] = min(dp[i][j], dp[i - 1][j] + traffic[i][j]);
//             }
//             if (j > 0) {
//                 dp[i][j] = min(dp[i][j], dp[i][j - 1] + traffic[i][j]);
//             }
//         }
//     }

//     if (dp[dest.first - 1][dest.second - 1] == INF) return -1; 
//     return dp[dest.first - 1][dest.second - 1];
// }

int main() {
    int n, m;
    cin >> n >> m;

    vvi traffic(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> traffic[i][j];
        }
    }

    pii start, dest;
    cin >> start.F >> start.S;
    cin >> dest.F >> dest.S;

    int result = minTrafficFlow(n, m, traffic, start, dest);
    cout << result << endl;

    return 0;
}
