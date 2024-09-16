class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0;
        int right = 0;
        deque<int> mini;
        deque<int> maxi;

        int ans = INT_MIN;
        int n = nums.size();
        while(right < n) {
            // insert in mini:
            while(!mini.empty() && mini.back() > nums[right]) mini.pop_back();
            mini.push_back(nums[right]);

            // insert in maxi:
            while(!maxi.empty() && maxi.back() < nums[right]) maxi.pop_back();
            maxi.push_back(nums[right]);

            // check for limit:
            while(abs(maxi.front() - mini.front()) > limit) {
                if(maxi.front() == nums[left]) maxi.pop_front();
                if(mini.front() == nums[left]) mini.pop_front();
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};