class Solution {
public:
    int binToDec(string& s) {
        int power = 0;
        int ans = 0;
        for(int i=s.size()-1; i>=0; i--) {
            ans += pow(2, power) * (s[i] - '0');
            power++;
        }
        return ans;
    }

    int matrixScore(vector<vector<int>>& grid) {
        // flip row if starting of row is 0: becoz if leftmost bit is 1, then decimal value will be bigger
        for(int i=0; i<grid.size(); i++) {
            if(grid[i][0] == 0) {
                for(int j=0; j<grid[i].size(); j++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        // flip col if number of zeros are more than ones: 8 4 2 1 , let's say 4 is the colums and there are 2 zeros and one ones. 
        // it means it will add only 4 in ans. but if you flip it, there will be 2 ones and one zero, means 4 + 4 = 8 in ans. so more ans
        for(int i=0; i<grid[0].size(); i++) {
            // count zeros and ones:
            int zeros = 0;
            int ones = 0;
            for(int j=0; j<grid.size(); j++) {
                if(grid[j][i]) ones++;
                else zeros++;
            }

            // flip if zeros more:
            if(zeros > ones) {
                for(int j=0; j<grid.size(); j++) {
                    grid[j][i] = !grid[j][i];
                }
            }
        }

        // find ans:
        int ans = 0;
        for(int i=0; i<grid.size(); i++) {
            string temp = "";
            for(int j=0; j<grid[i].size(); j++) temp.push_back('0' + grid[i][j]);
            ans += binToDec(temp);
        }
        return ans;
    }
};