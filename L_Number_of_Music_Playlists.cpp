class Solution {
public:
    int mod = 1000000007;
    long long solve(int n, int goal, int k, int noOFSongsPlayed)
    {
        if(n == 0 && goal == 0) return 1; // both goal and no of songs are 0
        if((n != 0 && goal == 0) || (n == 0 && goal != 0)) return 0; // when goal is done but all the songs are not played, it is not a possible case

        long long newSongPick = solve(n-1, goal-1, k, noOFSongsPlayed+1) * n; // we have n possbie options to pick any one of  them

        long long oldSongPick = solve(n, goal-1, k, noOFSongsPlayed) * max(0, noOFSongsPlayed-k); // here we have to choose from already picked songs on the condition that there should be k songs before we play any song again

        long long total = (newSongPick + oldSongPick) % mod;
        return total;
    }

    long long solve2(int n, int goal, int k, int noOFSongsPlayed, vector<vector<int>>& dp)
    {
        if(n == 0 && goal == 0) return 1; // both goal and no of songs are 0
        if((n != 0 && goal == 0) || (n == 0 && goal != 0)) return 0; // when goal is done but all the songs are not played, it is not a possible case

        if(dp[n][goal] != -1) return dp[n][goal];

        long long newSongPick = solve2(n-1, goal-1, k, noOFSongsPlayed+1, dp) * n; // we have n possbie options to pick any one of  them

        long long oldSongPick = solve2(n, goal-1, k, noOFSongsPlayed, dp) * max(0, n-k); // here we have to choose from already picked songs on the condition that there should be k songs before we play any song again
        
        long long total = (newSongPick + oldSongPick) % mod;
        dp[n][goal] = total;

        return total;
    }

    long long solve3(int n, int goal, int k)
    {
        vector<vector<int>> dp (n+1, vector(goal+1, 0));

        dp[0][0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=goal; j++)
            {
                long long newSongPick = dp[i-1][j-1] * 1LL * i; // we have n possbie options to pick any one of  them

                long long oldSongPick = dp[i][j-1] * 1LL * max(0, i-k); // here we have to choose from already picked songs on the condition that there should be k songs before we play any song again
                
                long long total = (newSongPick + oldSongPick) % mod;
                dp[i][j] = total;
            }
        }

        return dp[n][goal];
    }

    int numMusicPlaylists(int n, int goal, int k) {
        // return solve(n, goal, k, 0);

        // vector<vector<int>> dp (n+1, vector<int> (goal+1, -1));
        // return solve2(n, goal, k, 0, dp);

        return solve3(n, goal, k);
    }
};