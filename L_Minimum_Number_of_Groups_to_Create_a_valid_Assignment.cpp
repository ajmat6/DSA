class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        // finding freq of each element:
        for(auto i: nums)
        {
            mp[i]++;
        }

        // finding min freq:
        int mini = INT_MAX;
        for(auto i: mp)
        {
            if(i.second < mini) mini = i.second;
        }

        // checking groups from min freq size to 1 and whichever first freq size makes them possible to group is our ans:
        // TC = O(n) => as let min freq is m, then no of distinct elements can be n / m where n are total no of elements; therefore outer * inner loop = m * n / m = n
        int ans = INT_MAX;
        for(int i=mini; i>=1; i--)
        {
            // checking group size for i + 1 and i:
            int temp = 0;
            for(auto j: mp)
            {
                int quo = j.second / (i + 1);
                int rem = j.second % (i + 1);

                if(rem == 0)
                {
                    temp += quo;
                }

                else
                {
                    if(i - rem <= quo) temp += quo + 1;
                    else 
                    {
                        temp = INT_MAX;
                        break;
                    }
                }
            }

            if(temp != INT_MAX) return temp;
        }
        
        return -1; // not reachable
    }
};