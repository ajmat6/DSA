class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long count1 = 0;
        for(long long i=0; i<nums1.size(); i++)
        {
            sum1 += nums1[i];
            if(nums1[i] == 0) count1++;
        }
        
        long long sum2 = 0;
        long long count2 = 0;
        for(long long i=0; i<nums2.size(); i++)
        {
            sum2 += nums2[i];
            if(nums2[i] == 0) count2++;
        }
        
        // if((sum1 <= sum2 && count1 == 0 && count2 != 0) || (sum2 <= sum1 && count2 == 0)) return -1;
        
        long long minSum1 = sum1 + count1;
        long long minSum2 = sum2 + count2;
        
        if(minSum1 == minSum2) return minSum1;
        if(minSum1 < minSum2 && count1 != 0) return minSum2;
        if(minSum2 < minSum1 && count2 != 0) return minSum1;
        else return -1;
    }
};