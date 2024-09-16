class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // using space:
        // vector<int> temp;
        // int left = 0;
        // int right = 0;

        // while(left < m && right < n) {
        //     if(nums1[left] <= nums2[right]) {
        //         temp.push_back(nums1[left]);
        //         left++;
        //     }
        //     else {
        //         temp.push_back(nums2[right]);
        //         right++;
        //     }
        // }

        // while(left < m) {
        //     temp.push_back(nums1[left]);
        //     left++;
        // }

        // while(right < n) {
        //     temp.push_back(nums2[right]);
        //     right++;
        // }

        // for(int i=0; i<(m + n); i++) {
        //     nums1[i] = temp[i];
        // }





        // without extra space:
        int index = nums1.size() - 1; // yaha jo greater aaye vo daalana he
        int left = m - 1;
        int right = n - 1;

        while(left >= 0 && right >= 0) {
            if(nums1[left] >= nums2[right]) {
                nums1[index] = nums1[left];
                left--;
            }
            else {
                nums1[index] = nums2[right];
                right--;
            }
            index--;
        }

        while(left >= 0) {
            nums1[index] = nums1[left];
            left--;
            index--;
        }

        while(right >= 0) {
            nums1[index] = nums2[right];
            right--;
            index--;
        }
    }
};