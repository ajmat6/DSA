#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<pair<int, int>, __gnu_pbds::null_type, less<pair<int, int>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

// ordered_set ka order_of_key() method gives no of element in the set which are strictly less than the value passes in the order of key method
// to insert duplicate elements, you can us pair<int, int> where first is element and second is index. But then you have to make changes in the above imported headerfiles
// now to search you can use {element for whom you have to find no of less element, -1};
// TC of order_of_key() method is  logn
class Solution {
    // Overall TC is O(nlogn) and sc is O(n)
public:
    void insert(vector<int>& arr, ordered_set& st, int val, int index) {
        arr.push_back(val);
        st.insert({val, index});
    }

    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1; vector<int> arr2;
        ordered_set st1; ordered_set st2;
        arr1.push_back(nums[0]); arr2.push_back(nums[1]);
        st1.insert({nums[0], 0}); st2.insert({nums[1], 1});

        for(int i=2; i<nums.size(); i++) {
            int count1 = arr1.size() - st1.order_of_key({nums[i] + 1, -1});
            int count2 = arr2.size() - st2.order_of_key({nums[i] + 1, -1});
            if(count1 > count2) insert(arr1, st1, nums[i], i);
            else if(count2 > count1) insert(arr2, st2, nums[i], i);
            else {
                if(arr1.size() <= arr2.size()) insert(arr1, st1, nums[i], i);
                else insert(arr2, st2, nums[i], i);
            }
        }
        
        vector<int> ans;
        for(auto i: arr1) ans.push_back(i);
        for(auto i: arr2) ans.push_back(i);
        return ans;
    }
};