class Solution {
public:
    int pivotInteger(int n) {
        int i = 1; int sum = 0;
        for(i; i<=n; i++) sum += i;

        i = 1; int sum2 = 0; int ans = -1;
        while(sum2 <= sum && i <= n) {
            sum2 += i;
            int firstSum = sum2;
            int secondSum = sum - sum2 + i;
            if(firstSum == secondSum) {
                ans = i;
                break;
            }
            else i++;
        }

        return ans;
    }
};