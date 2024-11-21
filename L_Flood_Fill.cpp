class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(vector<vector<int>>& image, int row, int col, int color, int initial) {
        for(int i=0; i<4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if(newRow >= 0 && newRow < image.size() && newCol >= 0 && newCol < image[0].size() && image[newRow][newCol] == initial) {
                image[newRow][newCol] = color;
                dfs(image, newRow, newCol, color, initial);
            }
        }
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image; 
        
        int initial = image[sr][sc];
        image[sr][sc] = color;
        dfs(image, sr, sc, color, initial);
        return image;
    }
};