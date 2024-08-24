class Solution {
public:
    int solve(string& s, int index, int& countA) {
        if(index == s.size()) return 0;

        int ans = solve(s, index + 1, countA);
        if(s[index] == 'a') countA++;
        else  ans = min(ans + 1, countA);
        return ans;
    }

    int minimumDeletions(string s) {
        // 2pass and n space:
        // int n = s.size();
        // vector<int> leftB (n);
        // vector<int> rightA (n);
        // int totalB = s[0] == 'b' ? 1 : 0; int totalA = s[n - 1] == 'a' ? 1 : 0;
        // for(int i=1; i<n; i++) {
        //     leftB[i] = totalB;
        //     if(s[i] == 'b') totalB++;
        //     rightA[n-1-i] = totalA;
        //     if(s[n-1-i] == 'a') totalA++;
        // }

        // int ans = INT_MAX;
        // for(int i=0; i<n; i++) ans = min(ans, leftB[i] + rightA[i]);
        // return ans;



        // // 2pass and constant space:
        // int n = s.size();
        // int totalB = s[0] == 'b' ? 1 : 0;
        // int totalA = 0;
        // for(auto i: s) totalA += (i == 'a') ? 1 : 0;
        // int ans = s[0] == 'a' ? totalA - 1 : totalA;
        // for(int i=1; i<n; i++) {
        //     if(s[i - 1] == 'a') totalA--;
        //     ans = min(ans, totalB + (s[i] == 'a' ? totalA - 1 : totalA));
        //     totalB += s[i] == 'b' ? 1 : 0;
        // }

        // return ans;



        // // 1 pass and constant space:
        // int ans = 0; int totalB = 0;
        // for(auto i: s) {
        //     if(i == 'a') ans = min(ans + 1, totalB);
        //     else totalB++;
        // }
        // return ans;




        // using recursion:
        int countA = 0;
        return solve(s, 0, countA);
    }
};