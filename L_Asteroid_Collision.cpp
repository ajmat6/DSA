class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int i=0; i<asteroids.size(); i++)
        {
            // if curr element is postive push in stack:
            if(asteroids[i] > 0) st.push(asteroids[i]);

            // if curr element element is negative, then check:
            else
            {
                // popping from stack when stack element absolute value is lesser than current value
                while(st.size() > 0 && st.top() > 0 && abs(asteroids[i]) > abs(st.top()))
                {
                    st.pop();
                }

                // now if stack element is equal to current element:
                if(st.size() > 0 && st.top() > 0 && abs(asteroids[i]) == abs(st.top()))
                {
                    st.pop(); // and ignore current element
                }

                // if stack positive element is greater than absolute value of current element:
                else if(st.size() > 0 && st.top() > 0 && abs(asteroids[i]) < abs(st.top()))
                {
                    // ignore current element
                }

                // if stack top is also negative:
                else
                {
                    st.push(asteroids[i]);
                }
            }
        }

        vector<int> ans;
        // storing stack elements in ans vector:
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        // reverse ans elements as stack follow LIFO:
        reverse(ans.begin(), ans.end());
        return ans;
    }
};