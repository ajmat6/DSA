class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // using map:
        // unordered_map<int, int> mp1;
        // unordered_map<int, int> mp2;

        // for(auto i: nums1) mp1[i]++;
        // for(auto i: nums2) mp2[i]++;

        // vector<int> ans;
        // for(auto i: nums1) {
        //     if(mp2.find(i) != mp2.end() && mp2[i] > 0) {
        //         ans.push_back(i);
        //         mp2[i]--;
        //     }
        // }
        // return ans;


        // using sort:
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int n1 = 0, n2 = 0;
        vector<int> ans;
        while(n1 < nums1.size() && n2 < nums2.size()) {
            if(nums1[n1] == nums2[n2]) {
                ans.push_back(nums1[n1]);
                n1++;
                n2++;
            }
            else if(nums1[n1] < nums2[n2]) n1++;
            else n2++;
        }
        return ans;
    }
};