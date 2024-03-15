class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // count no of ones in s: TC is O(n) and SC is O(1)
        // int count = 0;
        // for(int i=0; i<s.size(); i++) {
        //     if(s[i] == '1') count++;
        // }

        // for(int i=0; i<s.size(); i++) {
        //     if(count <= 1) s[i] = '0';
        //     else s[i] = '1'; 
        //     count--;
        // }

        // s[s.size() - 1] = '1';
        // return s;

        // using stl count method and string creation method: TC is O(n) and SC is O(1)
        // int ones = count(s.begin(), s.end(), '1'); // no of ones
        // int n = s.size(); // total size
        // int zeros = n - ones;
        // return string(ones - 1, '1') + string(zeros, '0') + string(1, '1');


        // using sort: TC is O(nlogn) and SC is O(1)
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == '1') {
                swap(s[i], s[s.size()-1]);
                break;
            }
        }
        return s;
    }
};