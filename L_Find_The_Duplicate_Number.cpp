// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         // Using cycle detection: TC = O(n) and SC = O(1)
//         // for(auto i: nums)
//         // {
//         //     int num = abs(i);
//         //     if(nums[num] < 0)
//         //     {
//         //         return num;
//         //     }

//         //     else
//         //     {
//         //         nums[num] = -nums[num];
//         //     }
//         // }

//         // return 0;


//         // Using floyds cycle detection: TC = O(n) and SC = O(1)
//         // int slow = nums[0]; 
//         // int fast = nums[0];

//         // do
//         // {
//         //     // slow one time and fast time move forward:
//         //     slow = nums[slow];
//         //     fast = nums[nums[fast]];
//         // }while(fast != slow);

//         // // now again move both once at a time:
//         // fast = nums[0];

//         // while(fast != slow)
//         // {
//         //     slow = nums[slow];
//         //     fast = nums[fast];
//         // }

//         // return slow;

//         // return nums[slow];

//         int low = 1;
//         int high = nums.size() - 1;

//         while(low < high)
//         {
//             int mid = low + (high - low) / 2;

//             int count = 0;
//             for(auto i: nums)
//             {
//                 if(nums[i] >= low && nums[i] <= mid) count++;
//             }
//             cout << low << high << endl;

//             if(count > mid - low + 1) high = mid;
//             else low = mid + 1;

//         }

//         return low;

//         // using sorting: TC = O(nlogn) SC = O(1);
//         // sort(nums.begin(), nums.end());
//         // for(int i=1; i<nums.size(); i++)
//         // {
//         //     if(nums[i] == nums[i - 1]) return nums[i];
//         // }

//         // return 0;

//         // Using sets: TC = O(n) and SC = O(n)
//         // unordered_set<int> st;
//         // for(int i=0; i<nums.size(); i++)
//         // {
//         //     if(st.find(nums[i]) == st.end()) st.insert(nums[i]);
//         //     else return nums[i];
//         // }

//         // return 0;
//     }
// };

class Solution {
public:
  int help(vector<int>& nums, int low, int high) {
    int count = 0;
    for (const int& num : nums) {
        if (num >= low && num <= high) {
            count++;
        }
    }
    return count;
}

int findDuplicate(vector<int>& nums) {
    int low = 1;
    int high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = help(nums, low, mid);

        if (count > mid - low + 1) {
            high = mid;
        } 
        else {
            low = mid + 1;
        }
    }

    return low;
}
};