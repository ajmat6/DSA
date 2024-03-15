class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        // int n = words.size();
        // for(int i=0; i<n; i++) {
        //     int low = 0;
        //     int high = words[i].size() - 1;
        //     bool poss = true;
        //     while(low < high) {
        //         if(words[i][low] != words[i][high]) {
        //             poss = false;
        //         }
        //         low++;
        //         high--;
        //     }

        //     if(poss) return words[i];
        // }

        // return "";

        for(auto i: words) {
            string temp = i;
            reverse(i.begin(), i.end());
            if(temp == i) return temp;
        }
        return "";
    }
};