class Solution {
public:
    int solve(int n, int k)
    {
        // base case:
        if(n == 2)
        {
            if(k == 1) return 0;
            else return 1;
        }

        // finding place of the parent in previous row:
        int quo = k / 2;
        int rem = k % 2;
        int place = quo + rem;
        int temp = solve(n - 1, place);

        // if         
        if(temp == 0)
        {
            if(k % 2 == 0) return 1;
            else return 0;
        }

        else
        {
            if(k % 2 == 0) return 0;
            else return 1;
        }
    }

    int kthGrammar(int n, int k) {
        // if(n == 1) return 0;
        // else return solve(n, k);

        // iterative approach:
        int oppo = 0;
        int elements = pow(2, n - 1);

        while(elements != 1)
        {
            int halfValue = elements / 2;

            if(k > halfValue)
            {
                oppo++;
                k = k - halfValue;
            }

            elements /= 2;
        }

        if(oppo % 2 == 0) return 0;
        else return 1;
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
    