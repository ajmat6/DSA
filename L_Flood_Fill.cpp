class Solution {
public:
    void DFS(int row, int column, int inColor, int colour, vector<vector<int>>& image, vector<vector<int>>& image2)
    {
        image2[row][column] = colour; // changing present row and column block with new colour

        for(int newRow=-1; newRow<=1; newRow++)
        {
            for(int newCol=-1; newCol<=1; newCol++)
            {
                if(abs(newRow) + abs(newCol) == 2) continue;
                if(newRow == newCol) continue;

                int nowRow = newRow + row;
                int nowCol = newCol + column;

                // checking condition for further DFS call:
                if(nowRow >= 0  && nowRow < image.size() && nowCol >= 0 && nowCol < image[0].size() && image[nowRow][nowCol] == inColor && image2[nowRow][nowCol] != colour)
                {
                    DFS(nowRow, nowCol, inColor, colour, image, image2);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inColor = image[sr][sc]; 
        
        vector<vector<int>> image2 = image;
        DFS(sr, sc, inColor, color, image, image2);
        return image2;
    }
};