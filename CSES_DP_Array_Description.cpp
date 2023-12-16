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

int solve(vi& nums, int n, int m, int index, int prev, vvi& dp)
{
    if(index == n) return 1;

    if(dp[index][prev] != -1) return dp[index][prev];

    int ans = 0;
    if(index == 0)
    {
        if(nums[index] == 0)
        {
            for(int i=1; i<=m; i++)
            {
                nums[index] = i;
                ans = (ans + solve(nums, n, m, index + 1, i, dp)) % mod;
                nums[index] = 0;
            }
        }

        else ans = (ans + solve(nums, n, m, index + 1, nums[index], dp)) % mod;
    }

    else 
    {
        if(nums[index] == 0)
        {
            if(prev - 1 > 0)
            {
                nums[index] = prev - 1;
                ans = (ans + solve(nums, n, m, index + 1, prev - 1, dp)) % mod;
                nums[index] = 0;
            }
            nums[index] = prev;
            ans = (ans + solve(nums, n, m, index + 1, prev, dp)) % mod;
            nums[index] = 0;
            if(prev + 1 <= m) 
            {
                nums[index] = prev + 1;
                ans = (ans + solve(nums, n, m, index + 1, prev + 1, dp)) % mod;
                nums[index] = 0;
            }
        }

        else if(abs(nums[index] - nums[index - 1]) <= 1) ans = (ans + solve(nums, n, m, index + 1, nums[index], dp)) % mod;
    }

    return dp[index][prev] = ans;
}

int solve2(vi& nums, int n, int m)
{
    vvi dp (n + 1, vi (m + 1, 0));
    for(int i=0; i<dp[0].size(); i++)
    {
        dp[n][i] = 1;
    }

    for(int index=n-1; index>=0; index--)
    {
        for(int prev=m; prev>=0; prev--)
        {
            int ans = 0;
            if(index == 0)
            {
                if(nums[index] == 0)
                {
                    for(int i=1; i<=m; i++)
                    {
                        nums[index] = i;
                        ans = (ans + dp[index + 1][i]) % mod;
                        nums[index] = 0;
                    }
                }

                else ans = (ans + dp[index + 1][nums[index]]) % mod;
            }

            else 
            {
                if(nums[index] == 0)
                {
                    if(prev - 1 > 0)
                    {
                        nums[index] = prev - 1;
                        ans = (ans + dp[index + 1][prev - 1]) % mod;
                        nums[index] = 0;
                    }
                    nums[index] = prev;
                    ans = (ans + dp[index + 1][prev]) % mod;
                    nums[index] = 0;
                    if(prev + 1 <= m) 
                    {
                        nums[index] = prev + 1;
                        ans = (ans + dp[index + 1][prev + 1]) % mod;
                        nums[index] = 0;
                    }
                }

                else if(abs(nums[index] - nums[index - 1]) <= 1) ans = (ans + dp[index + 1][nums[index]]) % mod;
            }

            dp[index][prev] = ans;
        }
    }

    return dp[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vi nums (n);
    // for(int i=0; i<n; i++) cin >> nums[i];
    // vvi dp (n + 1, vi (m + 1, -1));
    // cout << solve(nums, n, m, 0, 0, dp) % mod;
    cout << solve2(nums, n, m) % mod;

    return 0;
}