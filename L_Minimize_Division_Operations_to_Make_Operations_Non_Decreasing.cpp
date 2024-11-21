class Solution {
public:
    int findDiv(int N, int next) {
        int ans = INT_MIN;
        for(int i=2; i*i<=N; i++) {
            if(N % i == 0 && N / i <= next) ans = max(ans, N / i);
            if(N % i == 0 && N / i > next && N / (N / i) <= next) ans = max(ans, N / (N / i));
        }
        return ans == INT_MIN ? INT_MAX : ans;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        int count = 0;
        int next = nums[n - 1];
        for(int i=n-2; i>=0; i--) {
            if(nums[i] <= next) {
                next = nums[i];
                continue;
            }
            else {
                int res = findDiv(nums[i], next);
                if(res > next) return -1;
                else next = res;
                count++;
            }
        }
        return count;
    }
};