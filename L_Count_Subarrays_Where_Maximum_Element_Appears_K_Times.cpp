class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // taking those subarrays into consideration where max element appear less than k times:
        // int maxi = INT_MIN;
        // for(auto i: nums) maxi = max(maxi, i);

        // long long n = nums.size();
        // long long totalSubarray = n * (n + 1) / 2;

        // int low = 0;
        // int high = 0;
        // int count = 0; long long ans = 0;
        // while(high < nums.size()) {
        //     if(nums[high] == maxi) count++;
        //     if(count < k) {
        //         ans += high - low + 1;
        //         high++;
        //     }
        //     else {
        //         while(low <= high && count == k) {
        //             if(nums[low] == maxi) {
        //                 if(low == high) {
        //                     count = 0;
        //                     high++;
        //                 }
        //                 else count -= 2;
        //             }
        //             low++;
        //         }
        //     }
        // }

        // return totalSubarray - ans;




        // taking into consideration the no of subarrays where max element appear at leat k times:
        int maxi = INT_MIN;
        for(auto i: nums) maxi = max(maxi, i);

        int low = 0;
        int high = 0;
        int count = 0; long long ans = 0;
        while(high < nums.size()) {
            if(nums[high] == maxi) count++;

            while(count >= k) {
                ans += nums.size() - high;
                if(nums[low] == maxi) count--;
                low++;
            }

            high++;
        }

        return ans;
    }
};