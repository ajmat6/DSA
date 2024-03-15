class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // int i = 0;
        // int j = 0;

        // while(i < nums1.size() && j < nums2.size()) {
        //     if(nums1[i] == nums2[j]) return nums1[i];
        //     else if(nums1[i] < nums2[j]) i++;
        //     else j++;
        // }

        // return -1;

        // using binary search:
        int n = nums1.size(); int m = nums2.size();
        if(n > m) {
            swap(nums1, nums2);
            swap(n, m);
        }

        int searched = 0;
        for(int i=0; i<n; i++) {
            int element = nums1[i];
            int index = lower_bound(nums2.begin() + searched, nums2.end(), element) - nums2.begin();
            if(nums2[index] == element) return element;
            else searched = index; // to start searching from this index from the next time
        }

        return -1;
    }
};