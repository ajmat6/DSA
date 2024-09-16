int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int ans = 0;
    int currXor = 0;
    for(auto i: A) {
        currXor ^= i;
        int toFind = B ^ currXor;
        ans += mp[toFind];
        mp[currXor]++;
    }
    return ans;
}
