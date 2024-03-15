class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int i = 1;
        while(i < 10) {
            int j = i;
            string temp = to_string(j);
            while(j < 10) {
                int val = stoi(temp);
                if(val >= low && val <= high){
                    ans.push_back(val);
                } 
                j++;
                temp += to_string(j);
            }
            i++;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};