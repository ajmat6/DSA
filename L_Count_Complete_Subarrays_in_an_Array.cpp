class Solution {
public:
    bool checkForComSubArray(int low, int high, vector<int>& nums, int dist)
    {
        set<int> s;
        for(int i=low; i<=high; i++)
        {
            s.insert(nums[i]);
        }
        
        if(s.size() == dist) return true;
        else return false;
    }
    
    int countCompleteSubarrays(vector<int>& nums) {
        // no of distinct elements in array:
        set<int> s;
        for(auto i: nums)
        {
            s.insert(i);
        }
        
        int dist = s.size();
        int ans = 0;
        
        // checkig for every possible subarray:
        for(int i=0; i<nums.size(); i++)
        {
            set<int> st;
            int count = 0;
            for(int j=i; j<nums.size(); j++)
            {
                if(st.find(nums[j]) == st.end())
                {
                    st.insert(nums[j]);
                    count++;
                }
                
                if(count == dist) ans++;
            }
        }
        
        return ans;
    }
};