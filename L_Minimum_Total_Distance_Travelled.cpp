class Solution {
public:
    long long dfs(vector<int>& robots, vector<long long>& fact, int index1, int index2, vector<vector<long long>>& dp) {
        if(index1 == robots.size()) return 0;
        if(index2 == fact.size()) return 1e15;
        if(dp[index1][index2] != -1) return dp[index1][index2];

        long long fix = abs(robots[index1] - fact[index2]) + dfs(robots, fact, index1 + 1, index2 + 1, dp);
        long long skip = dfs(robots, fact, index1, index2 + 1, dp);
        return dp[index1][index2] = min(fix, skip);
    }

    long long tab(vector<int>& robots, vector<long long>& fact) {
        vector<vector<long long>> dp (robots.size() + 1, vector<long long> (fact.size() + 1, 1e15));
        for(int i=0; i<dp[0].size(); i++) dp[robots.size()][i] = 0;

        for(int index1=robots.size()-1; index1>=0; index1--) {
            for(int index2=fact.size()-1; index2>=0; index2--) {
                long long fix = abs(robots[index1] - fact[index2]) + dp[index1 + 1][index2 + 1];
                long long skip = dp[index1][index2 + 1];
                dp[index1][index2] = min(fix, skip);
            }
        }
        return dp[0][0];
    }

    long long SO(vector<int>& robots, vector<long long>& fact) {
        vector<long long> next (fact.size() + 1, 0), curr (fact.size() + 1, 0);
        curr[fact.size()] = 1e15;

        for(int index1=robots.size()-1; index1>=0; index1--) {
            for(int index2=fact.size()-1; index2>=0; index2--) {
                long long fix = abs(robots[index1] - fact[index2]) + next[index2 + 1];
                long long skip = curr[index2 + 1];
                curr[index2] = min(fix, skip);
            }
            next = curr;
            curr[fact.size()] = 1e15;
        }
        return curr[0];
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<long long> factories;
        for(auto i: factory) {
            for(int j=0; j<i[1]; j++) factories.push_back(i[0]);
        }

        // vector<vector<long long>> dp (robot.size() + 1, vector<long long> (factories.size() + 1, -1));
        // return dfs(robot, factories, 0, 0, dp);
        // return tab(robot, factories);
        return SO(robot, factories);
    }
};