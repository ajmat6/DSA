class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0;
        for(auto i: nums) {
            if(i) ones++;
        }
        if(ones) for(int i=0; i<ones-1; i++) nums.push_back(nums[i]);
        else return 0;

        int n = nums.size();
        int low = 0; int high = 0; int count = 0;
        while(high != ones - 1) nums[high++] == 1 ? count += 1 : count += 0;
        if(nums[high]) count++;
        int ans = INT_MAX;
        while(true) {
            ans = min(ans, ones - count);
            if(nums[low]) count--;
            low++;
            high++;
            if(high == n) break;
            else if(nums[high]) count++;
        }
        return ans;



        // circular traversal:
        // int ones = 0;
        // for(auto i: nums) {
        //     if(i) ones++;
        // }
        // if(!ones) return 0;

        // int n = nums.size();
        // int low = 0; int high = 0; int count = 0;
        // while(high != ones - 1) nums[high++] == 1 ? count += 1 : count += 0;
        // if(nums[high]) count++;
        // int ans = INT_MAX;
        // while(true) {
        //     ans = min(ans, ones - count);
        //     if(nums[low]) count--;
        //     low =  (low + 1) % n;
        //     high = (high + 1) % n;
        //     if(nums[high]) count++;
        //     if(low == 0) break;
        // }
        // return ans;
        
    }
};