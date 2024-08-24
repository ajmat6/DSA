class neighborSum {
public:
    int n;
    vector<vector<int>> matrix;
    neighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        matrix = grid;
    }
    
    int adjacentSum(int value) {
        int row, col;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == value) {
                    row = i;
                    col = j;
                    break;
                }
            }
        }

        int total = 0;
        if(col + 1 < n) total += matrix[row][col + 1];
        if(col - 1 >= 0) total += matrix[row][col - 1];
        if(row + 1 < n) total += matrix[row + 1][col];
        if(row - 1 >= 0) total += matrix[row - 1][col];
        return total;
    }
    
    int diagonalSum(int value) {
        int row, col;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == value) {
                    row = i;
                    col = j;
                    break;
                }
            }
        }

        int total = 0;
        if(row - 1 >= 0 && col - 1 >= 0) total += matrix[row - 1][col - 1];
        if(row - 1 >= 0 && col + 1 < n) total += matrix[row - 1][col + 1];
        if(row + 1 < n && col - 1 >= 0) total += matrix[row + 1][col - 1];
        if(row + 1 < n && col + 1 < n) total += matrix[row + 1][col + 1];
        return total;
    }
};