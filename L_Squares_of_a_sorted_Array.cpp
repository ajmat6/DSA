class Solution {
public:
    vector<int> countSort(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++) {
            if(nums[i] > maxi) maxi = nums[i];
        }

        vector<int> count (maxi + 1);
        vector<int> ans (n);
        for(auto i: nums) count[i]++;
        for(int i=1; i<maxi + 1; i++) count[i] += count[i - 1];
        for(int i=n-1; i>=0; i--) {
            int index = count[nums[i]]--;
            ans[index-1] = nums[i];
        }
        return ans;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        // using two pointers: TC is O(n) and sc is O(n)
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--) {
            if(abs(nums[low]) >= abs(nums[high])) {
                ans[i] = nums[low] * nums[low];
                low++;
            }
            else {
                ans[i] = nums[high] * nums[high];
                high--;
            }
        }
        return ans;



        // using priority_queue: TC is O(n) and SC is O(n):
        // for(int i=0; i<nums.size(); i++) nums[i] = (nums[i] * nums[i]);
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for(auto i: nums) pq.push(i);
        // for(int i=0; i<nums.size(); i++) {
        //     nums[i] = pq.top(); pq.pop();
        // }
        // return nums;

        // using count sort: TC is O(n) and SC is O(n):
        // for(int i=0; i<nums.size(); i++) nums[i] *= nums[i];
        // vector<int> ans = countSort(nums);
        // return ans;

        // sort: TC is nlogn and sc is costant:
        // for(int i=0; i<nums.size(); i++) nums[i] *= nums[i];
        // sort(nums.begin(), nums.end());
        // return nums;
    }
};