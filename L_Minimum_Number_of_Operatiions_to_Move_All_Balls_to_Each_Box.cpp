class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int ones = boxes[n - 1] - '0';
        vector<int> suffix (n, 0);
        for(int i=n-2; i>=0; i--) {
            suffix[i] = suffix[i + 1] + ones;
            if(boxes[i] == '1') ones++;
        }

        vector<int> ans; ones = 0; 
        int prevPrefix = 0;
        for(int i=0; i<n; i++) {
            int prefixSum = prevPrefix + ones;
            prevPrefix += ones;
            if(boxes[i] == '1') ones++;
            ans.push_back(prefixSum + suffix[i]);
        }
        return ans;
    }
};