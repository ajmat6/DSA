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

void dfs(vll nums, bool& poss, ll& count) {
    if(nums.size() <= 2) {
        if(nums[0] <= nums[1]) poss = true;
        return;
    } 

    vector<int> temp;
    temp.push_back(nums[0]);
    temp.push_back(nums[1]);
    temp.push_back(nums[2]);

    sort(temp.begin() , temp.end());

    ll median = temp[1];
    bool found = false;
    vll newArray;
    for(int i=0; i<nums.size(); i++) {
        if(found == false && nums[i] == median) found = true;
        else newArray.push_back(nums[i]);
    }
    count += 1;
    dfs(newArray, poss, count);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        vll nums (n);
        for(int i=0; i<n; i++) cin >> nums[i];

        bool poss = false;
        ll count = 0;
        dfs(nums, poss, count);

        if(!poss) cout << "-1\n";
        else {
            cout << count << "\n";
            for(ll i=0; i<count; i++) {
                cout << "1 3\n";
            }
        }
    }

    return 0;
}