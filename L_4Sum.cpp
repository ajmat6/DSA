class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // // brute force: using set, sorting and n^4 time
        // int n = nums.size();
        // set<vector<int>> st;
        // for(int i=0; i<n; i++) {
        //     for(int j=i+1; j<n; j++) {
        //         for(int k=j+1; k<n; k++) {
        //             for(int l=k+1; l<n; l++) {
        //                 if((long long)nums[i] + nums[j] + nums[k] + nums[l] == target) {
        //                     vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
        //                     sort(temp.begin(), temp.end());
        //                     st.insert(temp);
        //                 } 
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans (st.begin(), st.end());
        // return ans;


        // // brute force: using set, sorting and n^3logn time and n space
        // int n = nums.size();
        // set<vector<int>> st;
        // unordered_map<long long, long long> mp;
        // sort(nums.begin(), nums.end());
        // for(int i=0; i<n; i++) {
        //     for(int j=i+1; j<n; j++) {
        //         for(int k=j+1; k<n; k++) {
        //             long long sum = nums[i] + nums[j];
        //             sum += nums[k];
        //             long long rem = target - sum;
        //             if(mp.find(rem) != mp.end()) {
        //                 vector<int> temp = {nums[i], nums[j], nums[k], (int)rem};
        //                 sort(temp.begin(), temp.end());
        //                 st.insert(temp);
        //             }
        //             mp[nums[k]] = k;
        //         }
        //         mp.clear();
        //     }
        // }
        // vector<vector<int>> ans (st.begin(), st.end());
        // return ans;


        // // using sort and two pointers: n^3 time complexity:
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j=i+1; j<n; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                long long rem = target - ((long long)nums[i] + nums[j]);
                int low = j + 1;
                int high = n - 1;

                while(low < high) {
                    if((long long)nums[low] + nums[high] > rem) high--;
                    else if((long long)nums[low] + nums[high] < rem) low++;
                    else {
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;

                        while(low < high && nums[low] == nums[low - 1]) low++;
                        while(low < high && nums[high] == nums[high + 1]) high--;
                    }
                }
            }
        }
        return ans;
    }
};