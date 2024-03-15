class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        vector<int> b(3);
        vector<int> notB(3);
        set<pair<int, int>> st;
        int n = grid.size();
        int half = n / 2;
        int yTotal = 0;
        for(int i=0; i<=half; i++) {
            int value = grid[i][i];
            b[value]++;
            st.insert({i, i});
            cout << i << " " << i << endl;
            yTotal++;
        }
        int row = 0; // 0
        int col = n - 1; // 2
        while(true) {
            st.insert({row, col});
            b[grid[row][col]]++;
            row++; col--;
            yTotal++;
            if(row == col) break;
        }
        
        for(int i=half+1; i<n; i++) {
            b[grid[i][half]]++;
            st.insert({i, half});
            yTotal++;
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(st.find({i, j}) == st.end()) notB[grid[i][j]]++;
            }
        }
        
        int total = n * n;
        int rem = total - yTotal;
        int ans = total;
        for(int i=0; i<3; i++) {
            int first = b[i];
            for(int j=0; j<3; j++) {
                if(i != j) {
                    int temp = yTotal - first + (rem - notB[j]);
                    if(temp < ans) ans = temp;
                }
            }
        }
        
        return ans;
    }
};