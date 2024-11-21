class Solution {
public:
    vector<string> stringSequence(string target) {
        string temp = "a";
        vector<string> ans;
        while(true) {
            while(temp.back() != target[temp.size() - 1]) {
                ans.push_back(temp);
                if(temp.back() == 'z') temp.back() = 'a';
                else temp.back() += + 1;
            }
            ans.push_back(temp);
            if(temp == target) break;
            temp.push_back('a');
        }
        return ans;
    }
}; 