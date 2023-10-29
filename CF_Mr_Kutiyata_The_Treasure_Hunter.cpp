#include<bits/stdC++.h>
using namespace std;
typedef long long ll;
int arr[30001];
int gems[30001] = {0};

int solve(int pos, int jump, int lastPosition)
{
    if(pos > lastPosition) return 0;

    int ans = gem[pos];

    // taking a jump of jump - 1;
    int less = solve(pos + jump - 1, jump - 1);
    int equal = solve(pos + jump, jump);
    int more = solve(pos + jump + 1, jump + 1);

    ans = ans + max(less, max(equal, more));
    return ans;
}

int main()
{
    ll n, d;
    cin >> n >> d;

    int gemPlace;
    int lastPosition;
    for(int i=0; i<n; i++)
    {
        cin >> gemPlace;
        gems[gemPlace]++;
        lastPosition = gemPlace;
    }

    if(gem[0] != 0) ans += gem[0];
    if(gem[d] != 0) ans += gem[d];
    
    cout << solve(d, d, lastPosition);

    return 0;
}