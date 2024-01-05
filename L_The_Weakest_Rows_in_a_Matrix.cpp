class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> v;

        // count through brute force:
        // for(int i=0; i<mat.size(); i++)
        // {
        //     int count = 0;
        //     for(int j=0; j<mat[0].size(); j++)
        //     {
        //         if(mat[i][j] == 1) count++;
        //     }

        //     v.push_back({count, i});
        // }

        // count through binary search:

        // nlogn
        for(int i=0; i<mat.size(); i++)
        {
            int low = 0;
            int high = mat[i].size() - 1;
            while(low <= high)
            {
                int mid = low + (high - low) / 2;

                if(mat[i][mid] == 1)
                {
                    low = mid + 1;
                }

                else
                {
                    high = mid - 1;
                }
            }

            v.push_back({low, i});
        }

        sort(v.begin(), v.end()); // nlogn

        vector<int> ans;
        for(int i=0; i<k; i++)
        {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};