class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int low = 0, high = people.size() - 1;
        int ans = 0;
        while(low <= high) {
            if(low != high && people[low] <= limit - people[high]) low++;
            ans++; high--;
        }
        return ans;
    }
};