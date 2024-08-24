class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int cell = 0;
        int row = 0;
        int col = 0;

        for(auto i: commands) {
            if(i == "RIGHT") col++;
            else if(i == "DOWN") row++;
            else if(i == "UP") row--;
            else col--;
            cell = (row * n) + col;
        }

        return cell;
    }
};