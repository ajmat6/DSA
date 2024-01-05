class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;

        // iterate over path string and insert directory names to stack, ignore / and . and also pop one direc name when .. comes:

        for(int i=0; i<path.size(); i++)
        {
            if(path[i] == '/') continue;

            // other than /, direc name, . and .. can come:
            // storing elements in string after / till next / comes:
            string temp;
            while(i<path.size() && path[i] != '/')
            {
                temp += path[i];
                i++;
            }

            // if temp is . then igonre temp:
            if(temp == ".") continue;

            // if temp is .. then pop one direc to go back:
            else if(temp == "..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }

            // else temp is a direc name and push it to stack:
            else
            {
                st.push(temp);
            }
        }

        // create ans string:
        // if ans string is /a/b/c then in stack they are stored in c, b, a form:
        string ans;
        while(!st.empty())
        {
            ans = "/" + st.top() + ans; // above reason
            st.pop();
        }

        // for cases like /../ stack will be emtpy, but we have to return /:
        if(ans.size() == 0) return "/";
        else return ans;
    }
};