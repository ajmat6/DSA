class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int low = 0;
        // int high = nums.size() - 1;

        // int ans = INT_MIN;
        // while(low < high)
        // {
        //     ans = max(ans, nums[low] + nums[high]);
        //     low++;
        //     high--;
        // }

        // return ans;

        // using count sort:
        // find max element in the array for count array size:
        int maxElement = INT_MIN;
        for(auto i: nums) maxElement = max(maxElement, i);
        vector<int> count (maxElement + 1);
        vector<int> sorted (nums.size());

        // find count of each element:
        for(auto i: nums)
        {
            count[i]++;
        }

        // take previous count in consideration:
        for(int i=1; i<count.size(); i++)
        {
            count[i] += count[i-1];
        }

        // iterate from the last of the original array and find its postion in count array:
        for(int i=nums.size()-1; i>=0; i--)
        {
            int element = nums[i];
            int index = count[element] - 1;
            count[element]--;
            sorted[index] = element;
        }

        int low = 0;
        int high = sorted.size() - 1;

        int ans = INT_MIN;
        while(low < high)
        {
            ans = max(ans, sorted[low] + sorted[high]);
            low++;
            high--;
        }

        return ans;
    }
};