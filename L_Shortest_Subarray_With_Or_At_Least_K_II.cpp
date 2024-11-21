class Solution {
public:
    void setBits(vector<int>& freq, int num) {
        for(int i=0; i<32; i++) {
            if(num & (1 << i)) freq[i]++;
        }
    }

    void unsetBits(vector<int>& freq, int num, int& currOr) {
        for(int i=0; i<32; i++) {
            if(num & (1 << i)) {
                freq[i]--;
                if(freq[i] == 0) {
                    currOr ^= (1 << i);
                }
            }
        }
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k == 0) return 1;
        vector<int> freq (32);
        int currOr = 0, low = 0, high = 0, n = nums.size(), ans = INT_MAX;
        while(high < n) {
            while(high < n && currOr < k) {
                currOr |= nums[high];
                setBits(freq, nums[high]);
                high++;
            }

            while(low <= high && currOr >= k) {
                ans = min(ans, high - low);
                unsetBits(freq, nums[low], currOr);
                low++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};