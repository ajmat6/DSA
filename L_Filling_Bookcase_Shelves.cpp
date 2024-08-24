class Solution {
public:
    int solve(vector<vector<int>>& books, int width, int index, vector<int>& dp) {
        if(index == books.size()) return 0;

        if(dp[index] != -1) return dp[index];

        // I will create a new shelf here:
        int currWidth = 0;
        int maxHeight = INT_MIN;
        int ans = INT_MAX;
        for(int i=index; i<books.size(); i++) {
            currWidth += books[i][0];
            maxHeight = max(maxHeight, books[i][1]);
            if(currWidth <= width) ans = min(ans, maxHeight + solve(books, width, i + 1, dp));
            else break;
        }
        return dp[index] = ans;
    }

    int tab(vector<vector<int>>& books, int width) {
        int n = books.size();
        vector<int> dp (n + 1, -1); dp[n] = 0;
        for(int index=n-1; index>=0; index--) {
            int currWidth = 0;
            int maxHeight = INT_MIN;
            int ans = INT_MAX;
            for(int i=index; i<n; i++) {
                currWidth += books[i][0];
                maxHeight = max(maxHeight, books[i][1]);
                if(currWidth <= width) ans = min(ans, maxHeight + dp[i + 1]);
                else break;
            }
            dp[index] = ans;
        }

        return dp[0];
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // recursive + memorisation: n^2 time and n space for dp array + recursive stack depth space
        // vector<int> dp (books.size() + 1, -1);
        // return solve(books, shelfWidth, 0, dp);

        // tabulation:
        return tab(books, shelfWidth); // n^2 time and n space without recursive stack depth space
    }
};