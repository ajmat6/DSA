class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // using sort: nlogn and constant space:
        // sort(nums.begin(), nums.end());
        // int i = 0;
        // while(i < nums.size() && nums[i] <= 0) i++;
        // int ans = 1;
        // while(i < nums.size()) {
        //     if(nums[i] != ans) return ans;
        //     else {
        //         while(i < nums.size() && nums[i] == ans) i++;
        //         ans++;
        //     }
        // }
        // return ans;




        // using vector: n space and time:
        // vector<int> temp (nums.size(), -1);
        // for(auto i: nums) {
        //     if(i > 0 && i <= temp.size()) temp[i - 1] = 1;
        // }

        // for(int i=0; i<temp.size(); i++) {
        //     if(temp[i] == -1) return i + 1;
        // }

        // return temp.size() + 1;




        // using sign change: n time and constant space
        // int size = nums.size();
        // for(int i=0; i<size; i++) {
        //     if(nums[i] <= 0 || nums[i] > size) nums[i] = 0;
        // }

        // for(int i=0; i<size; i++) {
        //     if(nums[i] != 0) {
        //         int value = abs(nums[i]);
        //         if(nums[value - 1] > 0) nums[value - 1] *= -1;
        //         else if(nums[value - 1] == 0) nums[value - 1] = -value;
        //     }
        // }

        // for(int i=0; i<size; i++) {
        //     if(nums[i] >= 0) return i + 1;
        // }

        // return size + 1;




        // swap and take current at its place: n time and constant space: (cyclic sort)
        // int size = nums.size();
        // for(int i=0; i<size; i++) {
        //     while(nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i]) swap(nums[i], nums[nums[i] - 1]);
        // }

        // for(int i=0; i<size; i++) {
        //     if(nums[i] != i + 1) return i + 1;
        // }

        // return size + 1;
    }
};