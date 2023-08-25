class Solution {
public:
    vector<pair<int, int>> quantity = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};

    // Recursion:
    double solve(int vol1, int vol2)
    {
        // Base Cases:
        if(vol1 == 0 && vol2 != 0) return 1;
        if(vol1 == 0 && vol2 ==  0) return 0.5;
        if(vol1 != 0 && vol2 == 0) return 0;

        // Taking every four possible cases:
        double ans = 0;
        for(int i=0; i<4; i++)
        {
            // volumes left after each case:
            int remVol1 = vol1 - quantity[i].first;
            int remVol2 = vol2 - quantity[i].second;

            // if rem volumes becomes negative, then send 0:
            ans += 0.25 * solve(max(0, remVol1), max(0, remVol2));
        }

        return ans;
    }

    // Memorisation:
    double solve2(int vol1, int vol2, vector<vector<double>>& dp)
    {
        if(vol1 == 0 && vol2 != 0) return 1;
        if(vol1 == 0 && vol2 ==  0) return 0.5;
        if(vol1 != 0 && vol2 == 0) return 0;

        // check for dp:
        if(dp[vol1][vol2] != -1) return dp[vol1][vol2];

        double ans = 0;
        for(int i=0; i<4; i++)
        {
            int remVol1 = vol1 - quantity[i].first;
            int remVol2 = vol2 - quantity[i].second;

            // if rem volumes becomes negative, then send 0:
            ans += 0.25 * solve2(max(0, remVol1), max(0, remVol2), dp);
        }

        // store in dp:
        dp[vol1][vol2] = ans;

        return ans;
    }

    // Tabulation:
    double solve3(int vol1, int vol2)
    {
        vector<vector<double>> dp (vol1+1, vector<double> (vol2+1, 0));

        // Handling base Cases:
        dp[0][0] = 0.5;
        for(int i=0; i<dp.size(); i++)
        {
            if(i == 0) continue;
            dp[0][i] = 1;
        }

        for(int vol1=1; vol1<dp.size(); vol1++)
        {
            for(int vol2=0; vol2<dp.size(); vol2++)
            {
                if(vol2 == 0) continue;
                double ans = 0;
                for(int i=0; i<4; i++)
                {
                    int remVol1 = vol1 - quantity[i].first;
                    int remVol2 = vol2 - quantity[i].second;

                    // if rem volumes becomes negative, then send 0:
                    ans += 0.25 * dp[max(0, remVol1)][max(0, remVol2)];

                    dp[vol1][vol2] = ans;
                }
            }
        }

        return dp[vol1][vol2];
    }

    double soupServings(int n) {
        if(n > 4800) return 1;
        // Recursion:
        // return solve(n, n);

        // Memorisation:
        // vector<vector<double>> dp (n+1, vector<double> (n+1, -1));
        // return solve2(n, n, dp);

        // Tabulation:
        return solve3(n, n);
    }
};