class Solution {
  public:
    void dfs(vector<int>& arr, int index, int sum, vector<int>& ans) {
        if(index == arr.size()) {
            ans.push_back(sum);
            return;
        }
        
        dfs(arr, index + 1, sum + arr[index], ans);
        dfs(arr, index + 1, sum, ans);
    }
    
    vector<int> subsetSums(vector<int> arr, int n) {
        // using bit manipulation: power set: 2^n * n time and const space:
        // int total = pow(2, n);
        // vector<int> ans;
        // for(int i=0; i<total; i++) {
        //     int sum = 0;
        //     for(int j=0; j<n; j++) {
        //         if((1 << (n - 1 - j)) & i) sum += arr[j];
        //     }
        //     ans.push_back(sum);
        // }
        // return ans;
        
        
        // using recursion: 2^n time and space:
        vector<int> ans;
        dfs(arr, 0, 0, ans);
        return ans;
    }
};