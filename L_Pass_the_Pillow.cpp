class Solution {
public:
    int passThePillow(int n, int time) {
        int quo = time / (n - 1);
        int rem = time % (n - 1);
        return quo % 2 == 0 ? rem + 1 : n - rem;
    }
};