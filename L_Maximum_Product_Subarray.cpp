class Solution {
public:
    void solve(vector<int>& nums, int index, int prev, int& ans)
    {
        if(index == nums.size())
        {
            ans = max(ans, prev * 1);
            return;
        }

        int temp = prev * nums[index];
        ans = max(ans, temp);
        solve(nums, index + 1, prev * nums[index], ans);
        ans = max(ans, nums[index]);
        solve(nums, index + 1, nums[index], ans);
    }

    int maxProduct(vector<int>& nums) {
        // int ans = INT_MIN;
        // solve(nums ,0, 1, ans);b
        // return ans;

        // prefix and suffix product array that will store product till current index:
        // when current index element is zero we will start form there again:
        // when current element is negative we will check its left and right side for the max product possible and same in the case of zero:
        if(nums.size() == 1) return nums[0];

        int negative = 0;
        int zeros = 0;

        for(auto i: nums)
        {
            if(i < 0) negative++;
            if(i == 0) zeros++;
        }

        vector<int> prefixProduct (nums.size(), 0);
        vector<int> suffixProduct (nums.size(), 0);

        int product = 1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                prefixProduct[i] = 0;
                product = 1;
            }

            else 
            {
                prefixProduct[i] = product * nums[i];
                product *= nums[i];
            }
        }

        if(negative % 2 == 0 && zeros == 0) return prefixProduct[nums.size()-1];

        product = 1;
        for(int i=nums.size()-1; i>=0; i--)
        {
            if(nums[i] == 0)
            {
                suffixProduct[i] = 0;
                product = 1;
            }

            else 
            {
                suffixProduct[i] = product * nums[i];
                product *= nums[i];
            }
        }

        int ans = INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] <= 0)
            {
                int left, right;
                if(i != 0) left = prefixProduct[i-1];
                else left = INT_MIN;

                if(i != nums.size()-1) right = suffixProduct[i+1];
                else right = INT_MIN;

                ans = max(ans, max(left, right));
            }

            // if(nums[i] == 0)
            // {
            //     ans = max(ans, max(prefixProduct[i-1], suffixProduct[i+1]));
            // }
        }

        return ans;
    }
};