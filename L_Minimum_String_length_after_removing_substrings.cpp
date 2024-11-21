class Solution {
public:
    int minLength(string s) {
        // using stack: n time and n space:
        // stack<char> st;
        // for(auto i: s) {
        //     if(i == 'B' && !st.empty() && st.top() == 'A') st.pop();
        //     else if(i == 'D' && !st.empty() && st.top() == 'C') st.pop();
        //     else st.push(i);
        // }
        // return st.size();




        // without space: in place: n time and const space:
        int prev = 0;
        for(int curr=1; curr<s.size(); curr++) {
            if((prev >= 0 && s[prev] == 'A' && s[curr] == 'B') || (prev >= 0 && s[prev] == 'C' && s[curr] == 'D')) prev--;
            else s[++prev] = s[curr];
        }
        return prev + 1;
    }
};




class Solution {
public:
    int minLength(string s) {
        string s1 = "AB";
        string s2 = "CD";
        
        while(true) {
            int flag = 0;
            
            if(s.find(s1) != -1) {
                int index = s.find(s1);
                s.erase(index, 2);
                flag = 1;
            }
            
            if(s.find(s2) != -1) {
                int index = s.find(s2);
                s.erase(index, 2);
                flag = 1;
            }
            
            if(flag == 0) break;
        }
        
        return s.size();
    }
};