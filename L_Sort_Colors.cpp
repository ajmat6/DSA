class Solution {
public:
    void sortColors(vector<int>& nums) {
        // using sort function: nlogn time and const space
        // sort(nums.begin(), nums.end());

        // using map: nlogn time and const space (only 3 unique elements are there)
        // map<int, int> mp;
        // for(auto i: nums) mp[i]++;
        // int index = 0;
        // for(auto i: mp) {
        //     for(int j=0; j<i.second; j++) {
        //         nums[index++] = i.first;
        //     }
        // }

        // using two pointers: n time and const space
        // int curr = 0;
        // for(int i=0; i<3; i++) {
        //     for(int j=curr; j<nums.size(); j++) {
        //         if(nums[j] == i) {
        //             swap(nums[curr], nums[j]);
        //             curr++;
        //         }
        //     }
        // }

        // using count: n time and const space
        // int ones = 0, twos = 0, zeros = 0;
        // for(auto i: nums) {
        //     if(i == 0) zeros++;
        //     else if(i == 1) ones++;
        //     else twos++;
        // }
        // for(int i=0; i<zeros; i++) nums[i] = 0;
        // for(int i=zeros; i<(zeros +ones); i++) nums[i] = 1;
        // for(int i=zeros + ones; i<(zeros + ones + twos); i++) nums[i] = 2;

        // using dutch flag algo (Three pointers): Most optimal and expected -> n time and const space (in place)
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 2) {
                swap(nums[high], nums[mid]);
                high--;
            }
            else mid++;
        }
    }
};