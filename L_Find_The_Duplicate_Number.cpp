class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // for(auto i: nums) {
        //     int value = abs(i);
        //     if(nums[value - 1] < 0) return value;
        //     else nums[value - 1] *= -1;
        // }

        // return 0;



        // using binary search:
        // int low = 1;
        // int high = nums.size() - 1;

        // while(low < high) {
        //     int mid = low + (high - low) / 2;
            
        //     int count = 0;
        //     for(auto i: nums) {
        //         if(i >= low && i <= mid) count++;
        //     }

        //     if(count > mid - low + 1) high = mid;
        //     else low = mid + 1;
        // }

        // return high;


        // using bit manipulation: nlogn time (n for inner and logn as each no has logn set bits) and constant space
        // int ans = 0;
        // for(int i=0; i<=31; i++) {
        //     // find no of elements in nums have ith bit as 1:
        //     int mask = 1 << i;
        //     int count = 0; int count2 = 0;
        //     for(int j=0; j<nums.size(); j++) {
        //         if(nums[j] & mask) count++;
        //         if(j & mask) count2++;
        //     }

        //     if(count > count2) ans |= mask;
        // }

        // return ans;



        // using fast and slow pointer: n time and constant space
        int slow = nums[0];
        int fast = nums[0];

        // do while loop used because initially both slow and fast are equal
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(fast != slow);

        // again make slow at start:
        slow = nums[0];

        // now move slow and fast equally:
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};