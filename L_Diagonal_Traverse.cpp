class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // vector<int> ans;
        // unordered_map<int, vector<pair<int, int>>> mp;
        // int n = mat.size();
        // int m = mat[0].size();

        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //     {
        //         mp[i+j].push_back({i, mat[i][j]});
        //     }
        // }

        // ans.push_back(mat[0][0]);
        // int maxSum = (n - 1) + (m - 1);

        // bool rev = false;
        // for(int i=1; i<=maxSum; i++)
        // {
        //     if(rev)
        //     {
        //         reverse(mp[i].begin(), mp[i].end());
        //         rev = false;
        //     } 
        //     else rev = true;
            
        //     for(auto j: mp[i]) ans.push_back(j.second);
        // }

        // return ans;



        // Using BFS:
        vector<int> ans;
        queue<pair<int, int>> q;
        q.push({0, 0});
        bool rev = false;

        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            for(int i=0; i<size; i++)
            {
                auto front = q.front();
                q.pop();
                int row = front.first;
                int col = front.second;
                temp.push_back(mat[row][col]);

                if(i == 0)
                {
                    if(mat.size() > (row + 1)) q.push({row + 1, col});
                    if(mat[row].size() > col + 1) q.push({row, col + 1});
                }

                else
                {
                    if(mat[row].size() > col + 1) q.push({row, col + 1});
                }
            }

            if(rev)
            {
                reverse(temp.begin(), temp.end());
                rev = false;
            }
            else rev = true;

            for(auto j: temp) ans.push_back(j);
        }

        return ans;
    }
};


