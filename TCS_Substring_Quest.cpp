// SubString Quest
// Problem Description
// Raju and Rani like playing with strings, exploring the interesting patterns of smaller parts within them, called substrings.

// Presently, they are engrossed in a string-centric game and it is Raju's turn. His task involves two strings provided by Rani, namely S1 and S2. Raju is tasked with dividing the first string S1 into the fewest possible substrings, ensuring that all resulting substrings, whether in their original or reversed order, are present in S2 while also aiming for maximizing the length of current substring.

// For example, if S1 = "vanaja" and S2 = "rvanpnaja", then the output will be van|aja rather than va|naja.

// Note : The letter in the ith position in S1 can be used in exactly one substring of S1. The letters from S2 can be reused any number of times but the letters from S1 can be used only once. The letters are case sensitive in both the strings.

// Constraints
// 1 <= S1, S2 <= 10000

// The two strings S1, S2 consist of lower and upper case characters only.

// Input
// First line consists of a string S1.

// Second line consists of string S2.

// Output
// Print the string S1 as a concatenation of sub strings separated by '|'.

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// VaisHnavI

// VIvekanandaJasHnavi

// Output

// V|a|i|sHnav|I

// Explanation

// Every sub string that is present in V|a|i|sHnav|I is also present in S2 in original or reversed order. No other way of doing sub strings on S1 will give less number of sub strings than this. Hence, we print V|a|i|sHnav|I.

// Example 2

// Input

// sudHanShu

// qniwprvAvnaHSsH

// Output

// Impossible

// Explanation

// As we can see, its impossible to sub string the string S1 based given conditions, thus we print "Impossible".


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

bool isSubstringPresent(string s, string s2) {
    size_t pos = s2.find(s);
    if (pos != string::npos) {
        return true;
    }
    reverse(s.begin(), s.end());
    pos = s2.find(s);
    return pos != string::npos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1;
    cin >> s2;

    int n = s1.size();
    int m = s2.size();

    string ans = "";

    // iterate over s1 and find:
    int curr = 0;
    int prev = 0;
    bool poss = true;
    while(curr < n) {
        string str = "";
        str += s1[curr];
        while(true) {
            if(!isSubstringPresent(str, s2)) break;
            else {
                curr++;
                if(curr < n) str += s1[curr];
                else break;
            }
        }

        if(curr == prev) {
            poss = false;
            break;
        }

        else {
            int size = str.size();
            if(curr != n) {
                ans += str.substr(0, size - 1);
                // cout << str.substr(0, size - 1) <<" ";
                ans += '|';
                prev = curr;
            }
            else {
                ans +=  str.substr(0, size);
                break;
            }
        }
    }

    if(!poss) cout << "Impossible\n";
    else cout << ans << "\n";

    return 0;
}


// ll solve(vvi& grid, int row, int col, int& endRow, int& endCol, vvll& dp) {
//     int n = grid.size();
//     int m = grid[0].size();

//     if(row == endRow && col == endCol) return grid[row][col];

//     if(dp[row][col] != LLONG_MAX) return dp[row][col];
 
//     ll ans = LLONG_MAX;
//     if(row + 1 < n) ans = min(ans, grid[row][col] + solve(grid, row + 1, col, endRow, endCol, dp));
//     if(col + 1 < m) ans = min(ans, grid[row][col] + solve(grid, row, col + 1, endRow, endCol, dp));

//     return dp[row][col] = ans;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int n, m;
//     cin >> n >> m;

//     vvi grid (n, vi (m));
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<m; j++) cin >> grid[i][j];
//     }

//     int startRow, startCol, endRow, endCol;
//     cin >> startRow >> startCol;
//     cin >> endRow >> endCol;

//     startRow -= 1;
//     startCol -= 1;
//     endRow -= 1;
//     endCol -= 1;

//     if(endRow >= startRow && endCol >= startCol) {
//         vvll dp (n + 1, vll (m + 1, LLONG_MAX));
//         ll res = solve(grid, startRow, startCol, endRow, endCol, dp);
//         cout << res;
//     }

//     else cout << "-1";


//     return 0;
// }