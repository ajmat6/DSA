class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
       long long ans = 0;
       vector<int> isVisited (nums.size(), 0);

       for(int i=nums.size()-1; i>=0; i--)
       {
            long long temp = nums[i];
            int j = i-1;

            if(!isVisited[i])
            {
                isVisited[i] = true;
                while(j >= 0 && nums[j] <= temp)
                {
                    isVisited[j] = true;
                    temp += nums[j];
                    j--;
                }

                ans = max(ans, temp);
            }

       } 

       return ans;
    }
};