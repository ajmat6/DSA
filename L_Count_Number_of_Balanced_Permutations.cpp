#define ll long long 
class Solution {
public:
    const int mod = 1e9 + 7; 
    int binaryExpo(ll x, int power) {
        ll ans = 1;
        while(power != 0) {
            if(power % 2) {
                ans = (ans * 1LL * x) % mod;
                power--;
            } 
            else {
                x = (x * 1LL * x) % mod;
                power /= 2;
            }
        }
        return ans;
    }

    int dfs(string& num, int digit, int evenSum, int evenCount, int& totalSum, vector<int>& freq, int& permuteCount, vector<int>& ifact, vector<vector<vector<int>>>& dp) {
        if(digit == 10) {
            int half = (num.size() + 1) / 2;
            if(evenCount != half) return 0;
            return (evenSum == totalSum / 2) ? permuteCount : 0;
        }
        if(dp[digit][evenSum][evenCount] != -1) return dp[digit][evenSum][evenCount];

        int ans = 0;
        if(freq[digit] == 0) return dp[digit][evenSum][evenCount] = dfs(num, digit + 1, evenSum, evenCount, totalSum, freq, permuteCount, ifact, dp);

        for(int i=0; i<=min(freq[digit], (int)(num.size() + 1) / 2 - evenCount); i++) {
            int evenGo = i;
            int oddGo = freq[digit] - i;
            ll res = dfs(num, digit + 1, evenSum + (i * digit), evenCount + i, totalSum, freq, permuteCount, ifact, dp);
            res = (res * ifact[evenGo]) % mod;
            res = (res * ifact[oddGo]) % mod;
            ans = (ans + res) % mod;
        }
        return dp[digit][evenSum][evenCount] = ans;
    }

    int countBalancedPermutations(string num) {
        int totalSum = 0;
        int n = num.size();
        vector<int> freq (10), fact(n + 1, 1), ifact(n + 1, 1);
        for(auto &i: num) {
            totalSum += (i - '0');
            freq[i - '0']++;
        }
        if(totalSum % 2) return 0;

        for(int i=1; i<=n; i++) {
            fact[i] = (i * 1LL * fact[i - 1]) % mod;
            ifact[i] = binaryExpo(fact[i], mod - 2) % mod;
        }

        int permuteCount = (fact[n / 2] * 1LL * fact[(n + 1) / 2]) % mod;
        vector<vector<vector<int>>> dp (10, vector<vector<int>> (740, vector<int> (81, -1)));
        return dfs(num, 0, 0, 0, totalSum, freq, permuteCount, ifact, dp);
    }
};