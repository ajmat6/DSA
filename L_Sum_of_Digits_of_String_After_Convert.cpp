class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size();
        string temp = "";
        for(int i=0; i<n; i++) {
            int pos = s[i] - 'a' + 1;
            temp += to_string(pos);
        }
        
        for(int i=0; i<k; i++) {
            int sum = 0;
            for(int j=0; j<temp.size(); j++) {
                sum += temp[j] - '0';
            }
            temp = to_string(sum);
        }

        return stoi(temp);
    }
};