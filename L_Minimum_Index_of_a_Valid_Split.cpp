class Solution {
public:
    // int dominant(int low, int high, vector<int>& nums)
    // {
    //     unordered_map<int, int> mp;
    //     for(int i=low;i<=high;i++){
    //         mp[nums[i]]++;
    //     }
        
    //     int temp = -1;
    //     for(int i=low; i<=high; i++)
    //     {
    //         if(mp[nums[i]]*2 > high - low +1)
    //         {
    //             temp = nums[i];
    //             break;
    //         }
    //     }

    //     return temp;
    // }

    int minimumIndex(vector<int>& nums) {
        // Brute Force -> Gives TLE:
        // int ans = INT_MAX;
        // for(int i=0; i<nums.size()-1; i++)
        // {
        //     int left = dominant(0, i, nums);
        //     int right = dominant(i+1, nums.size()-1, nums);
            
        //     if(left == right)
        //     {
        //         ans = min(ans, i);
        //     }
        // }
        
        // if(ans == INT_MAX) return -1;
        // else return ans;

        // Second Approach:

        // Boyer Moore approach to find max occuring element:
        int most = nums[0];
        int mostCount = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == most) mostCount++;
            else mostCount--;

            if(mostCount == 0)
            {
                most = nums[i];
                mostCount = 1;
            }
        }

        // counting how many times most element is there in the array:
        mostCount = 0;
        for(int i=0;  i<nums.size(); i++)
        {
            if(nums[i] == most) mostCount++;
        }

        // valid split check: Keep in mind that same majority element will be majority element in subarrays then split is valid:
        int count = 0; // for counting mast element in the left subarray
        for(int i=0; i<nums.size(); i++)
        {
            // counting most element in the left subarray:
            if(nums[i] == most) count++;

            // valid split condition:
            if(count*2 > i+1 && (mostCount-count)*2 > nums.size()-i-1)
            {
                return i;
            }
        }

        return -1;
    }
};