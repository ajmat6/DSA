class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int size = nums.size();

        // vector<int> temp (size, -1);

        // for(int i=0; i<nums.size(); i++)
        // {
        //     if(nums[i] > size || nums[i] <= 0) continue;
        //     else temp[nums[i]-1] = 1;
        // }

        // for(int i=0; i<temp.size(); i++)
        // {
        //     if(temp[i] == -1) return i+1;
        // }

        // return size + 1;

        int size = nums.size();

        for(int i=0; i<size; i++)
        {
            while(nums[i] >= 1 && nums[i] <= size && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i=0; i<size; i++)
        {
            if(nums[i] != i + 1) return i + 1;
        }

        return size + 1;
    }
};