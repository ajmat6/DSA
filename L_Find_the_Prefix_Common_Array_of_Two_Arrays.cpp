class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int common = 0;
        vector<int> ans;
        int freq[51] = {0};
        for(int i=0; i<A.size(); i++) {
            if(++freq[A[i]] == 2) common++;
            if(++freq[B[i]] == 2) common++;
            ans.push_back(common);
        }
        return ans;
    }
};