class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalks = 0;
        int n = chalk.size();
        for(int i=0; i<n; i++) totalChalks += chalk[i];

        int rem = k % totalChalks;
        for(int i=0; i<n; i++) {
            if(rem < chalk[i]) return i;
            rem -= chalk[i];
        }
        return 0;
    }
};