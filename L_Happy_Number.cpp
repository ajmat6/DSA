class Solution {
public:
    int squareSum(int n)
    {
        int ans = 0;

        while(n>0)
        {
            int temp = n % 10;
            ans += temp * temp;
            n = n / 10;
        }

        return ans;
    }

    bool isHappy(int n) {
        // Applying Floyd's Cycle detection algo:
        int slow = n;
        int fast = squareSum(n);

        while(fast != 1 && fast != slow)
        {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        }

        return fast == 1;
    }
};