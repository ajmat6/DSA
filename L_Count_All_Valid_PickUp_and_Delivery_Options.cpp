class Solution {
public:
    const int MOD = 1e9 + 7;
    long long solve(int n)
    {
        if(n == 1) return 1;

        // permutation and combination problem: See dicussion
        long long ans = n * (2 * n - 1) * solve(n - 1) % MOD;
        return ans;
    }

    int countOrders(int n) {
        // Recursion:
        // return solve(n);


        // iterative:
        long long  totalSpace = 2 * n; // for n = 3, we have 6 spaces to fill
        long long ans = 1;

        for(int i=n; i>=1; i--)
        {
            ans = ans * (totalSpace * (totalSpace - 1) / 2) % MOD;
            totalSpace -= 2; // two space for one pickup and delivery
        }

        return (int)ans;
    }
};