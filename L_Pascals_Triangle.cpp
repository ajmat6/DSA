class Solution {
public:
    vector<int> generateRow(int rowNo) {
        vector<int> temp;
        temp.push_back(1);
        int ncr = 1;
        for(int col=1; col<rowNo; col++) {
            ncr = ncr * (rowNo - col);
            ncr = ncr / col;
            temp.push_back(ncr);
        }
        return temp;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++) {
            ans.push_back(generateRow(i));
        }

        return ans;
    }
};