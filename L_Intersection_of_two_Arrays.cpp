class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st, ans;
        for(auto i: nums1) st.insert(i);
        for(auto i: nums2) if(st.find(i) != st.end()) ans.insert(i);
        return {ans.begin(), ans.end()};
    }
};