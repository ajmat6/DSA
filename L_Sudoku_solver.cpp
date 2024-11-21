// TC is O(9^m) where m are no of empty places but slightly lower than second method as time is reduced to find the empty place:
// SC is O(m) to find the empty cells:
class Solution {
public:
    bool checkRowColBox(vector<vector<char>>& board, int i, int j, int k) {
        for(int row=0; row<9; row++) {
            if(board[i][row] - '0' == k) return false;
        }

        for(int col=0; col<9; col++) {
            if(board[col][j] - '0' == k) return false;
        }

        int rowStart = (i / 3) * 3;
        int colStart = (j / 3) * 3;
        for(int row=rowStart; row<rowStart+3; row++) {
            for(int col=colStart; col<colStart+3; col++) {
                if(board[row][col] - '0' == k) return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<char>>& board, vector<pair<int, int>>& emp, int index) {
        if(index == emp.size()) return true;

        int i = emp[index].first;
        int j = emp[index].second;

        for(int k=1; k<=9; k++) {
            if(checkRowColBox(board, i, j, k)) {
                board[i][j] = k + '0';
                if(dfs(board, emp, index + 1)) return true;;
                board[i][j] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> emp;
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') emp.push_back({i, j});
            }
        }

        dfs(board, emp, 0);
    }
};





// here sc is O(1)
class Solution {
public:
    bool checkRowColBox(vector<vector<char>>& board, int& i, int& j, int& k) {
        for(int row=0; row<9; row++) {
            if(board[i][row] - '0' == k) return false;
        }

        for(int col=0; col<9; col++) {
            if(board[col][j] - '0' == k) return false;
        }

        int rowStart = (i / 3) * 3;
        int colStart = (j / 3) * 3;
        for(int row=rowStart; row<rowStart+3; row++) {
            for(int col=colStart; col<colStart+3; col++) {
                if(board[row][col] - '0' == k) return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    for(int k=1; k<=9; k++) {
                        if(checkRowColBox(board, i, j, k)) {
                            board[i][j] = k + '0';
                            if(dfs(board)) return true;;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }
};