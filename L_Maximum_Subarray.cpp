class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // // brute force: n^3 solution
        // int n = nums.size();
        // int ans = INT_MIN;
        // for(int i=0; i<n; i++) {
        //     for(int j=i; j<n; j++) {
        //         int sum = 0;
        //         for(int k=i; k<=j; k++) {
        //             sum += nums[k];
        //         }
        //         ans = max(ans, sum);
        //     }
        // }
        // return ans;


        // better: n^2 solution
        // int n = nums.size();
        // int ans = INT_MIN;
        // for(int i=0; i<n; i++) {
        //     int sum = 0;
        //     for(int j=i; j<n; j++) {
        //         sum += nums[j];
        //         ans = max(ans, sum);
        //     }
        // }
        // return ans;


        // optimal solution(using kadanes algo): O(n) solution
        int sum = 0;
        int index = 0;
        int ans = INT_MIN;
        while(index < nums.size()) {
            sum += nums[index];
            ans = max(ans, sum);
            if(sum < 0) sum = 0;
            index++;
        }
        return ans;
    }
};