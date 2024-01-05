class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int i = 0;
        int j = i + indexDifference;

        int maxValue = nums[i];
        int minValue = nums[i];
        int maxIndex = i;
        int minIndex = i;

        while(j < nums.size())
        {
            if(abs(nums[j] - minValue) >= valueDifference) return {minIndex, j};
            else if(abs(nums[j] - maxValue) >= valueDifference) return {maxIndex, j};

            i++;
            j++;

            if(i != nums.size())
            {
                if(maxValue < nums[i])
                {
                    maxValue = nums[i];
                    maxIndex = i;
                }  

                if(minValue > nums[i])
                {
                    minValue = nums[i];
                    minIndex = i;
                }
            }

            else break;
        }

        return {-1, -1};
    }
};