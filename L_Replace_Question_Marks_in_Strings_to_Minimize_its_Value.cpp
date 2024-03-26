class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> freq (26, 0);
        vector<char> res;
        for(int j=0; j<s.size(); j++) {  
            if(s[j] != '?') freq[s[j] - 'a']++;
        }
        
        for(int j=0; j<s.size(); j++) {
            if(s[j] == '?') {
                int mini = INT_MAX;
                for(int i=0; i<26; i++) {
                    mini = min(mini, freq[i]);
                }
                
                for(int i=0; i<26; i++) {
                    if(freq[i] == mini) {
                        res.push_back('a' + i);
                        freq[i]++;
                        break;
                    }
                }
            }
        }
        
        sort(res.begin(), res.end());
        int index = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '?') {
                s[i] = res[index];
                index++;
            }
        }
        
        return s;
    }
};

"aabcaba"
0
"vvnowvov"
2
"htntthhntnn"
0