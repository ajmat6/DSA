class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // two pass:
        // int maxLength = 1;
        // int n = nums.size();
        // int maxi = *max_element(nums.begin(), nums.end());

        // for(int high=0, low=0; high<n; high++) {
        //     if(nums[high] != maxi) low++;
        //     else {
        //         while(high < n && nums[high] == maxi) high++;
        //         maxLength = max(maxLength, high - low);
        //         low = high;
        //         high--;
        //     }
        // }
        // return maxLength;



        // one pass: n time and constant space:
        int maxLength = 1;
        int n = nums.size();
        int maxi = INT_MIN;
        for(int high=0, low=0; high<n; high++) {
            if(nums[high] == maxi) {
                while(high < n && nums[high] == maxi) high++;
                maxLength = max(maxLength, high - low);
                low = high;
                high--;
            }

            else if(nums[high] > maxi) {
                maxi = nums[high];
                low = high;
                maxLength = 1;
            }

            else {
                low = high;
                low++;
            }
        }
        return maxLength;
    }
};