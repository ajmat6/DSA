class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int rollsSum = 0;
        for(auto i: rolls) rollsSum += i;
        int totalSum = mean * (n + m);

        int remSum = totalSum - rollsSum;
        int quo = remSum / n;
        int rem = remSum % n;

        if(remSum > n * 6 || remSum < n) return {};
        vector<int> ans (n, quo);
        int index = 0;
        for(int i=0; i<rem; i++) ans[i] = quo + 1; // rem will be always less than the quotient (which is less than or equal to 6 for each element in n)
        return ans;
    }
};