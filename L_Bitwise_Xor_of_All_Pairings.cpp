class Solution {
public:
    int doXor(vector<int>& nums1, vector<int>& nums2, int both) {
        int xorr = 0;
        for(auto &i: nums1) xorr ^= i;
        if(both) for(auto &i: nums2) xorr ^= i;
        return xorr;
    }

    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() % 2;
        int m = nums2.size() % 2;
        if(!n && !m) return 0; // both even size
        if(n && m) return doXor(nums1, nums2, 1); // both odd size (both array xor)
        else if(n && !m) return doXor(nums2, nums1, 0); // second even (second array xor)
        else return doXor(nums1, nums2, 0); // first even (first array xor)
    }
};