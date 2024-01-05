class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<int> heights (matrix[0].size());
        int ans = 0;

        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0) heights[j] = 0;
                else heights[j] += 1;
            }

            vector<int> temp = heights;
            sort(temp.begin(), temp.end());

            for(int i=0; i<temp.size(); i++)
            {
                int area = temp[i] * (temp.size() - i);
                ans = max(ans, area);
            }
        }

        return ans;
    }
};