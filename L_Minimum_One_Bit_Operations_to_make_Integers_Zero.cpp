class Solution {
public:
    int solve(int bitNo)
    {
        if(bitNo == 0) return 1;
        else return 2 * solve(bitNo - 1) + 1;
    }

    int minimumOneBitOperations(int n) {
        // using recursion:
        int bit = 0;
        stack<int> st;
        while(n != 0)
        {
            if(n & 1)
            {
                st.push(solve(bit));
            }

            bit++;
            n >>= 1;
        }

        int ans = 0;
        int flag = false;
        while(!st.empty())
        {
            int top = st.top();
            st.pop();
            if(flag)
            {
                ans -= top;
                flag = false;
            }
            else
            {
                ans += top;
                flag = true;
            }
        }

        return ans;


        // no of operation are equal to the binary no obtained after treating n as a gray code:
        // int ans = 0;
        // while(n != 0)
        // {
        //     ans ^= n;
        //     n >>= 1;
        // }

        // return ans;
    }
};