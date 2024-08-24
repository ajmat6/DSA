class Solution {
public:
    int minimumPushes(string word) {
        vector<int> arr(26, 0);
        for(auto i: word) arr[i - 'a']++;
        sort(arr.begin(), arr.end(), greater<int>());

        int ans = 0;
        for(int i=0; i<26; i++) {
            if(arr[i] == 0) break;
            if(i <= 7) ans += (arr[i] * 1);
            else if(i >= 8 && i<=15) ans += (arr[i] * 2);
            else if(i >= 16 && i <= 23) ans += (arr[i] * 3);
            else ans += (arr[i] * 4);
        }
        return ans;
    }
};