#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
vi lis;
vi arr;
vi ans;

void solve(int index, int prev, vector<vi>& dp)
{
    if(index == arr.size())
    {
        if(lis.size() > ans.size()) ans = lis;
        return;
    }

    if(dp[index][prev + 1] != -1) return dp[index][prev + 1];

    if(prev == -1 || arr[index] == prev + 1)
    {
        lis.push_back(index + 1);
        solve(index + 1, arr[index]);
        lis.pop_back();
    }

    solve(index + 1, prev);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; 
    ll maxi = INT_MIN;
    cin >> n;

    arr.resize(n);
    // vi hash (n);
    // vi dp (n, 1);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }

    // ll ans = 1;
    // ll lastIndex = 0;
    // for(int i=0; i<n; i++)
    // {
    //     hash[i] = i;
    //     int prevNum = arr[i] - 1;
    //     for(int prev=i-1; prev>=0; prev--)
    //     {
    //         if(arr[prev] == prevNum && dp[prev] + 1 > dp[i])
    //         {
    //             dp[i] = dp[prev] + 1;
    //             hash[i] = prev;
    //             prevNum--;
    //         }
    //     }

    //     if(dp[i] > ans)
    //     {
    //         ans = dp[i];
    //         lastIndex = i;
    //     }
    // }

    // // find the LIS to print:
    // vi lis;
    // lis.push_back(lastIndex + 1);
    // while(hash[lastIndex] != lastIndex)
    // {
    //     lastIndex = hash[lastIndex];
    //     lis.push_back(lastIndex + 1);
    // }

    // reverse(lis.begin(), lis.end());
    // cout << ans << "\n";
    // for(auto i: lis) cout << i << " ";  

    // Optimal using binary search:
    // vi lis;
    // vi index;
    // lis.push_back(arr[0]);
    // index.push_back(1);

    // for(int i=1; i<arr.size(); i++)
    // {
    //     if(arr[i] == lis.back() + 1)
    //     {
    //         lis.push_back(arr[i]);
    //         index.push_back(i + 1);
    //     } 
    //     else if(arr[i] > lis.back()) continue;
    //     else
    //     {
    //         int indexx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
    //         lis[indexx] = arr[i];
    //         index[indexx] = i + 1;
    //     }
    // }

    // cout << lis.size() << "\n";
    // for(auto i: index) cout << i << " ";

    vector<vi> dp (n + 1, vi (maxi + 1, -1));
    solve(0, -1, dp);

    cout << ans.size() << "\n";
    for(auto i: ans) cout << i << " ";


    return 0;
}