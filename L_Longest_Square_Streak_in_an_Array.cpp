class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto i: nums) mp[i]++;

        for(int i=0; i<n; i++) {
            long long x = nums[i];
            int currCount = 1;
            while(true) {
                if(x < 1000 && mp.count(x * 1LL * x)) currCount++;
                else break;
                x *= x;
            }
            if(currCount != 1) ans = max(ans, currCount);
        }
        return ans;
    }
};


#include<bits/stdc++.h>
using namespace std;
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

int solve() {