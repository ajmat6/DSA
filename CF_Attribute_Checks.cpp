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

int dfs(vi& nums, int index, int total, int in, vector<vi>& dp) {
    if(index == nums.size()) return 0;
    if(dp[total][in] != -1) return dp[total][in];

    if(nums[index] == 0) {
        int inPlus = dfs(nums, index + 1, total + 1, in + 1, dp);
        int stPlus = dfs(nums, index + 1, total + 1, in, dp);
        return dp[total][in] = max(inPlus, stPlus);
    }
 
    int check = dfs(nums, index + 1, total, in, dp);
    if(nums[index] > 0 && in >= nums[index]) check += 1;
    else if(nums[index] < 0 && (total - in) >= abs(nums[index])) check += 1;
    return dp[total][in] = check;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi nums (n);
    for(int i=0; i<n; i++) cin >> nums[i];

    // vi st, intl;
    vector<vi> dp (m + 1, vi (m + 1, -1));
    cout << dfs(nums, 0, 0, 0, dp);


    // cout << tab(nums, m);

    return 0;
}