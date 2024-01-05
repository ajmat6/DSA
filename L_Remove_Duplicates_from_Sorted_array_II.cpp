class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int ans = 0;
        // int track = 0;
        // int count = 0;
        // int val = nums[0];

        // while(track < nums.size())
        // {
        //     while(track < nums.size() && nums[track] == val)
        //     {
        //         count++;
        //         track++;
        //     }

        //     for(int i=0; i<min(2, count); i++) nums[ans++] = val;

        //     if(track < nums.size())
        //     {
        //         count = 0;
        //         val = nums[track];
        //     }
        // }


        // return ans;

        int ans = 0;
        for(auto i: nums)
        {
            if(ans < 2 || i > nums[ans - 2]) nums[ans++] = i;
        }

        return ans;
    }
};