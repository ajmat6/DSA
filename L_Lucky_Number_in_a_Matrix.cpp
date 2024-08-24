class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // in two pass: n * m time and n + m space for using set:
        // unordered_set<int> st;
        // for(int i=0; i<matrix.size(); i++) {
        //     int mini = INT_MAX;
        //     for(int j=0; j<matrix[i].size(); j++) mini = min(mini, matrix[i][j]);
        //     st.insert(mini);
        // }

        // vector<int> ans;
        // for(int i=0; i<matrix[0].size(); i++) {
        //     int maxi = INT_MIN;
        //     for(int j=0; j<matrix.size(); j++) maxi = max(maxi, matrix[j][i]);
        //     if(st.find(maxi) != st.end()) ans.push_back(maxi);
        //     else st.insert(maxi);
        // }

        // return ans;



        // in one pass: n * m time and const space if we dont include return ans vector:
        vector<int> ans;
        for(int i=0; i<matrix.size(); i++) {
            int mini = INT_MAX; int minIndex = -1;
            for(int j=0; j<matrix[i].size(); j++) {
                if(matrix[i][j] < mini) {
                    mini = matrix[i][j];
                    minIndex = j;
                }
            }

            // check if mini is the maxi element in its row:
            bool poss = true;
            for(int j=0; j<matrix.size(); j++) {
                if(matrix[j][minIndex] > mini) {
                    poss = false;
                    break;
                }
            }

            if(poss) ans.push_back(mini);
        }

        return ans;
    }
};