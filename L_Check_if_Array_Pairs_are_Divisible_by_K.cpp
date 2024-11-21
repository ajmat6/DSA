class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq (k);
        for(auto i: arr) {
            int rem = ((i % k) + k) % k; // + k is done for negative nos so that it will give us a positive rem:
            freq[rem]++;
        }

        if(freq[0] % 2 != 0) return false;
        for(int i=1; i<k/2; i++) {
            if(freq[i] != freq[k - i]) return false;
        }
        return true;
    }
};