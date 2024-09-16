class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obs) {
        // insert obstacles in a set:
        set<pair<int, int>> st;
        for(auto i: obs) {
            st.insert({i[0], i[1]});
        } 

        int row = 0;
        int col = 0;
        int curr = 1; // left=0, up=1, right=2, down=3;
        vector<vector<int>> moves = {{-1,0},{0,1},{1,0},{0,-1}}; // left, up, right, down
                                    // 0     1     2     3

        int ans = 0;
        for(auto i: commands) {
            if(i == -1) {
                if(curr == 3) curr = 0;
                else curr++;
            }

            else if(i == -2) {
                if(curr == 0) curr = 3;
                else curr--;
            }

            else {
                for(int j=0; j<i; j++) {
                    int nextRow = row + moves[curr][0];
                    int nextCol = col + moves[curr][1];

                    if(st.find({nextRow, nextCol}) == st.end()) {
                        row = nextRow;
                        col = nextCol;
                        ans = max(ans, row * row + col * col);
                    }
                    else break;
                }
            }
        }

        return ans;
    }
};