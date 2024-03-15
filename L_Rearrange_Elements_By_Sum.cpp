class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // vector<int> pos;
        // vector<int> neg;

        // for(auto i: nums) {
        //     if(i < 0) neg.push_back(i);
        //     else pos.push_back(i);
        // }

        // int first = 0;
        // int second = 0;
        // for(int i=0; i<nums.size(); i++) {
        //     if(i % 2 == 0) {
        //         nums[i] = pos[first];
        //         first++;
        //     }

        //     else {
        //         nums[i] = neg[second];
        //         second++;
        //     }
        // }

        // return nums;

        vector<int> ans (nums.size());
        int pos = 0;
        int neg = 1;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < 0) {
                ans[neg] = nums[i];
                neg += 2;
            }

            else {
                ans[pos] = nums[i];
                pos += 2;
            }
        }

        return ans;
    }
};