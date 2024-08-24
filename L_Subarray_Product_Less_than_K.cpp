class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // brute force: n^2 time and constant space
        // int ans = 0;
        // for(int i=0; i<nums.size(); i++) {
        //     long long mul = 1;
        //     for(int j=i; j<nums.size(); j++) {
        //         mul *= nums[j];
        //         if(mul < k) ans++;
        //         else break;
        //     }
        // }
        // return ans;





        // using two pointers
        if(k <= 1) return 0;
        int low = 0, high = 0;
        int ans = 0;
        int mul = 1;
        while(low <= high && high < nums.size()) {
            mul *= nums[high];
            while(mul >= k) {
                mul /= nums[low];
                low++;
            }
            ans += high - low + 1;
            high++;
        }
        return ans;
    }
};