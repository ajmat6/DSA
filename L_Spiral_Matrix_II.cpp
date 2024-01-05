class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans (n, vector<int> (n, 0));

        // variables to track starting row, col and ending row, col:
        int srow = 0;
        int scol = 0;
        int erow = n - 1;
        int ecol = n - 1;

        // total numbers that we have to insert in resultant matrix:
        int totalNumbers = n * n;
        int number = 1; // starting number

        // if number count is = to totalNumbers than still we have to fill one more block as number has become equal to totalNumber becoz of number++ in previous iteration:
        while(number <= totalNumbers)
        {
            // row fill at start in -> (right) direction:
            for(int i=scol; i<=ecol && number <= totalNumbers; i++)
            {
                ans[srow][i] = number;
                number++;
            }
            srow++;

            // col fill at end in down direction:
            for(int j=srow; j<=erow && number <= totalNumbers; j++)
            {
                ans[j][ecol] = number;
                number++;
            }
            ecol--;

            // row fill at end in <- (left) direction:
            for(int k=ecol; k>=scol && number <= totalNumbers; k--)
            {
                ans[erow][k] = number;
                number++;
            }
            erow--;

            // col fill at start in upward direction:
            for(int l=erow; l>=srow && number <= totalNumbers; l--)
            {
                ans[l][scol] = number;
                number++;
            }
            scol++;
        }

        return ans;
    }
};