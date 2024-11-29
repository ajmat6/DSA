#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Cell {
    int row, col, steps;
    Cell(int r, int c, int s) : row(r), col(c), steps(s){}
};

int minStepsToReachDestination(vector<vector<int>>& board, int N, int M, pair<int, int> start, pair<int, int> dest) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<Cell> q;

    int startRow = start.first, startCol = start.second;
    int count = 0;
    while(startRow != N - 1 && board[startRow + 1][startCol] != 1) {
        startRow++;
        count++;
    }
    q.push(Cell(startRow, startCol, count));
    visited[startRow][startCol] = true;


    while (!q.empty()) {
        Cell current = q.front();
        q.pop();
        int row = current.row;
        int col = current.col;
        int currSteps = current.steps;

        // assuming you have checked below lift case here:
        if (current.row == dest.first && current.col == dest.second) {
            return currSteps - 1;
        }

        for(int i=0; i<4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            int count = 0;
            if(newRow >= 0 && newRow < N && newCol >= 0 && newCol < M) {
                if(i == 0) {
                    if(board[newRow][newCol] != 1) continue;
                    else {
                        while(newRow >= 0 && board[newRow][newCol] == 1) {
                            newRow--;
                            count++;
                        }
                        if(newRow >= 0 && visited[newRow][newCol] == 0) {
                            visited[newRow][newCol] = 1;
                            q.push(Cell(newRow, newCol, currSteps + count + 1));
                        }
                    }
                }
                else if(i == 2) continue;
                else {
                    if(board[newRow][newCol] == 1) continue;
                    while(newRow != N - 1 && board[newRow + 1][newCol] != 1) {
                        newRow++;
                        count++;
                    }
                    if(visited[newRow][newCol] == 0) {
                        q.push(Cell(newRow, newCol, currSteps + count + 1));
                        visited[newRow][newCol] = 1;
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board;
    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<m; j++) {
            int no;
            cin >> no;
            temp.push_back(no);
        }
        board.push_back(temp);
    }
    pair<int, int> start;
    cin >> start.first >> start.second;

    pair<int, int> end;
    cin >> end.first >> end.second;

    if(end.first != n - 1 && board[end.first + 1][end.second] != 1) cout << "Impossible";
    else {
        int res =  minStepsToReachDestination(board, n, m, start, end);
        if(res == -1) cout << "Impossible";
        else cout << res;
    }



    return 0;
}
