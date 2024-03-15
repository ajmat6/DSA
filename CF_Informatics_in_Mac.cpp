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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vi nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];

        vi first, second;
        map<int, int> mp1, mp2;
        first.pb(nums[0]); mp1[nums[0]]++;
        for(int i=n-1; i>=1; i--) {
            second.pb(nums[i]);
            mp2[nums[i]]++;
        } 

        int mex1 = nums[0] == 0 ? 1 : 0;
        vi temp = second;
        sort(temp.begin(), temp.end());
        int mex2 = 0;
        for(auto i: mp2) {
            if(i.first == mex2) mex2 += 1;
            else break;
        }

        // now you have mex1, mex2 and first, second array:
        bool found = false;
        if(mex1 == mex2) found = true;
        else {
            while(second.size() != 1) {
                int rem = second.back(); second.pop_back(); first.pb(rem); // remove back element from second and insert it into the first
                mp1[rem]++; mp2[rem]--;
                if(rem == mex1) { // if inserted element is mex1
                    while(mp1.find(mex1) != mp1.end()) mex1 += 1;
                }

                if(rem < mex2) {
                    if(mp2[rem] == 0) mex2 = rem;
                }

                if(mex1 == mex2) {
                    found = true;
                    break;
                }
            }

        }
        
        if(!found) cout << "-1\n";
        else {
            cout << "2\n";
            cout << "1 " << first.size() << "\n";
            cout << first.size() + 1 << " " << n << "\n";
        }
    }

    return 0;
}