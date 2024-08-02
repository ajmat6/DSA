class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ajmat;
        for(auto i: nums1) ajmat.push_back(i);
        for(auto i: nums2) ajmat.push_back(i);

        // Sorting them:
        sort(ajmat.begin(), ajmat.end());

        int size = ajmat.size();

        if(size % 2 == 0)
        {
            return (ajmat[size/2-1] + ajmat[size/2])/2.0;
        } 

        else return ajmat[size/2];
    }
};