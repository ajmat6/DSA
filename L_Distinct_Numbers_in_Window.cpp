vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ans;
    unordered_map<int, int> mp;
    
    for(int i=0; i<B; i++) mp[A[i]]++;
    
    int low = 0;
    int high = B - 1;
    while(high < A.size()) {
        ans.push_back(mp.size());
        high++;
        if(high < A.size()) mp[A[high]]++;
        mp[A[low]]--;
        if(mp[A[low]] == 0) mp.erase(A[low]);
        low++;
    }
    return ans;
}
