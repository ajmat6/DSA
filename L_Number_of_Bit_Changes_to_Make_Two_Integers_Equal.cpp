class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        while(n != 0 || k != 0) {
            int temp = n & 1;
            int temp2 = k & 1;
            if(temp && !temp2) ans += 1;
            else if(!temp && temp2) return -1;
            n >>= 1;
            k >>= 1;
        }
        return ans;
    }
};