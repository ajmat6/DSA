class Solution {
public:
    // logic is that if I keep a alive for b's time, then what it will cost me. Whoever cost more, you need to kill it!
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return (a.first * b.second > b.first * a.second);
    }

    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        int totalDamage = 0;
        vector<pair<int, int>> damageTime;
        for(int i=0; i<n; i++) {
            int quo = health[i] / power;
            int rem = health[i] % power;
            int second = quo;
            second += rem == 0 ? 0 : 1;
            damageTime.push_back({damage[i], second});
            totalDamage += damage[i];
        }

        long long ans = 0;
        sort(damageTime.begin(), damageTime.end(), cmp);
        for(int i=0; i<n; i++) {
            int timeToKill = damageTime[i].second;
            ans += totalDamage * 1LL * timeToKill;
            totalDamage -= damageTime[i].first;
        }

        return ans;
    }
};