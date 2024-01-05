class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int total = 1;
        for(int i=1; i<n; i++)
        {
            nums.push_back(i);
            total = total * i;
        }
        nums.push_back(n);
        string ans = "";
        k = k - 1;
        while(true)
        {
            ans += to_string(nums[k / total]);
            nums.erase(nums.begin() + k / total);
            if(nums.size() == 0) break;
            k = k % total;
            total = total / nums.size();
        }

        return ans;
    }
};