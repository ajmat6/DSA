class Solution {
public:
    bool isPowerOfThree(int n) {
        // First method by using loops:
        // if(n == 0) return false;
        // if(n == 1) return true; // power 0 of three

        // while(n % 3 == 0) n = n / 3;
        // return n == 1;

        // Second method:
        // check divisibility with highest power of 3 as it is prime no:
        return n > 0 && 1162261467 % n == 0;
    }
};