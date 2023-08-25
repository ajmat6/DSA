class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> ajmat (32);
        int ans = 0;

        // counting each index no of bits in nums array:
        for(int i=0; i<32; i++)
        {
            int sum = 0; // to count each nums element each bit index
            for(int j=0; j<nums.size(); j++)
            {
                // checking if curr bit is 1:
                if(nums[j] & 1 == 1)
                {
                    sum++;
                }

                // right shifting curr bit so to check its 1's in next iteration:
                nums[j] = nums[j] >> 1;
            }

            // adding count of present bit index in ajmat array:
            ajmat[i] = sum;
        }

        for(int i=31; i>=0; i--)
        {
            ans = ans << 1;
            if(ajmat[i] % 3 != 0)
            {
                ans = ans | 1;
            }
        }
        
        return ans;
    }
};