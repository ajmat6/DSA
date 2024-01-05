class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // unordered_map<int, int> mp;
        // for(auto i: nums) mp[i]++;

        // int total = nums.size() / 3;
        // vector<int> ans;
        // for(auto i: mp) if(i.second > total) ans.push_back(i.first);
        // return ans;

        // Using Moore's Voting Alogorithm:
        int e1 = INT_MAX;
        int e2 = INT_MAX;
        int count1 = 0;
        int count2 = 0;

        int turn = 1;
        for(int i=0; i<nums.size(); i++)
        {
            if(count1 == 0 && nums[i] != e2)
            {
                e1 = nums[i];
                count1++;
            }

            else if(count2 == 0 && nums[i] != e1)
            {
                e2 = nums[i];
                count2++;
            }

            else if(nums[i] == e1) count1++;
            else if(nums[i] == e2) count2++;

            else
            {
                count1--;
                count2--;
                // if(count1 == 0) e1 = INT_MAX;
                // if(count2 == 0) e2 = INT_MAX;
            }
        }

        // verify algo:
        int realCount1 = 0;
        int realCount2 = 0;

        for(auto i: nums)
        {
            if(i == e1) realCount1++;
            else if(i == e2) realCount2++;
        }

        cout << e1 << " " << e2;

        vector<int> ans;
        if(realCount1 > nums.size() / 3) ans.push_back(e1);
        if(realCount2 > nums.size() / 3 ) ans.push_back(e2);

        return ans;
    }
};