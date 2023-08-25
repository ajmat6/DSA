class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        if(s.size() == 1) return s;
        if(s.size() < numRows) return s;

        int i = 0; // track over input string
        long long col = 0; // track over columns:
        int size = s.size();
        int cols = size; // no of columns

        char mat[numRows][cols];
        memset(mat, '/', sizeof(mat)); // initialising mat array with '/'


        mat[0][0] = s[i];
        i++;

        int j = 1;
        while(i < size)
        {
            // down move:
            for(j; j<numRows; j++)
            {
                if(i < size)
                {
                    mat[j][col] = s[i];
                    i++;
                }
                else break;
            }

            j--;
            col++;

            // up move:
            while(j > 1 && i < size)
            {
                if(i < size)
                {
                    cout << col << " ";
                    mat[j-1][col] = s[i];
                    i++;
                    j--;
                    col++;
                }

                else break;
            }

            j--;
        }

        string ans = "";
        for(int i=0; i<numRows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(mat[i][j] != '/')
                {
                    ans.push_back(mat[i][j]);
                }
            }
        }

        return ans;
    }
};