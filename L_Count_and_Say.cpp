class Solution {
public:
    string countAndSay(int n) {
        // if(n == 1) return "1";
        // string rec = countAndSay(n - 1);

        // int index = 0;
        // string ans = "";
        // int size = rec.size();
        // while(index < size) {
        //     char c = rec[index];
        //     int len = 0;
        //     while(index < size && rec[index] == c) {
        //         index++;
        //         len++;
        //     }
        //     ans.push_back(len + '0');
        //     ans.push_back(c);
        // }
        // return ans;



        // iterative: 
        string ans = "1";
        while(n > 1) {
            int index = 0;
            string temp = "";
            int size = ans.size();
            while(index < size) {
                int start = index;
                while(index < size && ans[index] == ans[start]) index++;
                temp.push_back((index - start) + '0');
                temp.push_back(ans[start]);
            }
            ans = temp;
            n--;
        }
        return ans;
    }
};