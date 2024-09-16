// class Solution {
// public:
//     pair<int, int> solve(vector<int>& piles, int index, int M, int turn, vector<vector<vector<pair<int, int>>>>& dp) {
//         int n = piles.size();
//         if(index == piles.size()) return {0, 0};

//         if(dp[index][M][turn].first != -1) return dp[index][M][turn];

//         int sum = 0;
//         int ans = INT_MIN;
//         int returnWala = 0;
//         for(int i=index; i<min(n, index + 2 * M); i++) {
//             sum += piles[i];
//             pair<int, int> call = solve(piles, i + 1, max(M, i - index + 1), !turn, dp);
//             if(sum + call.first > ans) {
//                 ans = sum + call.first;
//                 returnWala = call.second;
//             }
//         }

//         return dp[index][M][turn] = {returnWala, ans};
//     }

//     int stoneGameII(vector<int>& piles) {
//         int n = piles.size();
//         vector<vector<vector<pair<int, int>>>> dp (n, vector<vector<pair<int, int>>> (n + 1, vector<pair<int, int>> (2, {-1, -1})));
//         return solve(piles, 0, 1, 0, dp).second;
//     }
// };

class Solution {
public:
    int solve(vector<int>& piles, int index, int M, int turn, vector<vector<vector<int>>>& dp) {
        int n = piles.size();
        if(index == piles.size()) return 0;

        if(dp[index][M][turn] != -1) return dp[index][M][turn];

        int sum = 0;
        int ans = turn == 0 ? INT_MIN : INT_MAX;
        for(int i=index; i<min(n, index + 2 * M); i++) {
            sum += piles[i];
            int call = solve(piles, i + 1, max(M, i - index + 1), !turn, dp);
            if(turn == 0) ans = max(ans, sum + call);
            else ans = min(ans, call); // when it is bob's turn then he will try to reduce alice score so will paas min of possible in prev recursive calls
        }

        return dp[index][M][turn] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (n + 1, vector<int> (2, -1)));
        return solve(piles, 0, 1, 0, dp);
    }
};