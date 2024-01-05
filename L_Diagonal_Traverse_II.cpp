class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // vector<pair<int, pair<int, int>>> temp;
        // for(int i=0; i<nums.size(); i++)
        // {
        //     for(int j=0; j<nums[i].size(); j++)
        //     {
        //         temp.push_back({i + j, {i, nums[i][j]}});
        //     }
        // }

        // sort(temp.begin(), temp.end());
        // vector<int> ans;
        // vector<int> tempy;
        // int prev = 0;
        // for(int i=0; i<temp.size(); i++)
        // {
        //     int sum = temp[i].first;
        //     int element = temp[i].second.second;

        //     if(sum == prev)
        //     {
        //         tempy.push_back(element);
        //     }

        //     else
        //     {
        //         for(int j=tempy.size()-1; j>=0; j--) ans.push_back(tempy[j]);

        //         tempy = {};
        //         prev = sum;
        //         tempy.push_back(element);
        //     }
        // }

        // for(int i=tempy.size()-1; i>=0; i--) ans.push_back(tempy[i]); // for last (row + col) sums as it will not go in else part in last iteration in above for loop
        // return ans;



        // Using BFS:
        vector<int> ans;
        queue<pair<int, int>> q;
        q.push({0, 0});

        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                auto front = q.front();
                q.pop();
                int row = front.first;
                int col = front.second;
                ans.push_back(nums[row][col]);

                if(i == 0)
                {
                    if(nums.size() > (row + 1) && nums[row + 1].size() > col) q.push({row + 1, col});
                    if(nums[row].size() > col + 1) q.push({row, col + 1});
                }

                else
                {
                    if(nums[row].size() > col + 1) q.push({row, col + 1});
                }
            }
        }

        return ans;
    }
};