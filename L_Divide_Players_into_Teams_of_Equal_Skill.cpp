class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // using sort and two pointers: nlogn + n time:
        // sort(skill.begin(), skill.end());
        // int low = 0;
        // int high = skill.size() - 1;
        // int oneTeam = skill[low] + skill[high];
        // long long ans = skill[low++] * skill[high--];
        // while(low < high) {
        //     if(skill[low] + skill[high] != oneTeam) return -1;
        //     else ans += (skill[low] * skill[high]);
        //     low++;
        //     high--;
        // }
        // return ans;



        // using hashmap frequency count:
        long long sum = 0;
        int n = skill.size();
        for(auto i: skill) sum += i;

        int totalTeams = n / 2;
        if(sum % totalTeams != 0) return -1;
        int oneTeam = sum / totalTeams;

        unordered_map<int, int> mp;
        for(auto i: skill) mp[i]++;

        long long ans = 0;
        for(int i=0; i<n; i++) {
            if(!mp.count(skill[i])) continue; // previously taken
            int rem = oneTeam - skill[i];
            if(!mp.count(rem)) return -1;
            mp[rem]--;
            mp[skill[i]]--;
            if(mp[rem] == 0) mp.erase(rem);
            if(mp[skill[i]] == 0) mp.erase(skill[i]);
            ans += (skill[i] * rem);
        }
        return ans;
    }
};