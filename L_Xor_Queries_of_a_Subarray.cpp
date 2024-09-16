class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int currXor = 0;
        int n = arr.size();
        vector<int> prefix(n);
        for(int i=0; i<n; i++) {
            currXor ^= arr[i];
            prefix[i] = currXor;
        }

        vector<int> ans;
        for(auto &i: queries) {
            int start = i[0];
            int end = i[1];
            if(start == 0) ans.push_back(prefix[end]);
            else ans.push_back(prefix[end] ^ prefix[start - 1]);
        }
        return ans;
    }
};