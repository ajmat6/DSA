class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;

        if(dp[n] != -1) return dp[n];
        else return dp[n] =  solve(n - 1, dp) + solve(n - 2, dp) + solve(n - 3, dp);
    }

    int tab(int N) {
        vector<int> dp (N + 3, 0);
        dp[1] = dp[2] = 1;
        for(int n=3; n<=N; n++) {
            dp[n] =  dp[n - 1] + dp[n - 2] + dp[n - 3];
        }
        return dp[N];
    }

    int spaceOpt(int N) {
        if(N == 0) return 0;
        int third = 1, second = 1, first = 0;
        for(int n=3; n<=N; n++) {
            int temp = first + second + third;
            first = second;
            second = third;
            third = temp;
        }
        return third;
    }

    int tribonacci(int n) {
        // vector<int> dp (n + 1, -1);
        // return solve(n, dp);
        // return tab(n);
        return spaceOpt(n);
    }
};