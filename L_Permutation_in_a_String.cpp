class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n2 < n1) return false;

        vector<int> freq1 (26, 0), freq2 (26, 0);
        for(int i=0; i<n1; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        int low = 0;
        int high = n1 - 1;
        while(high < n2) {
            if(freq1 == freq2) return true;
            freq2[s2[low++] - 'a']--;
            high++;
            if(high < n2) freq2[s2[high] - 'a']++;
        }
        return false;
    }
};