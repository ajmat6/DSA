class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff (n);
        diff[0] = s[0] - 'a';
        for(int i=1; i<n; i++) diff[i] = s[i] - s[i - 1];

        for(int i=0; i<shifts.size(); i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int change = shifts[i][2];

            // when 1 -> add +1 to start index in diff and add -1 to end + 1
            // when 0 -> add -1 to start index in diff and add +1 to end + 1;
            if(change == 1) {
                diff[start] += 1;
                if(end != n - 1) diff[end + 1] -= 1;
            }
            else {
                diff[start] -= 1;
                if(end != n - 1) diff[end + 1] += 1;
            }
        }

        // final changes
        for(int i=1; i<n; i++) diff[i] += diff[i - 1];
        for(int i=0; i<n; i++) {
            int shift = (diff[i] % 26 + 26) % 26; // mod equivalent property for negative nos
            s[i] = 'a' + shift;
        }
        return s;
    }
};