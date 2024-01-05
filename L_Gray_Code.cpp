class Solution {
public:
    int appendOne(int number, int bitPlace)
    {
        // setting the bitPlace bit as 1
        return number | (1 << (bitPlace - 1));
    }

    vector<int> solve(int n)
    {
        if(n == 1) return {0, 1};

        vector<int> temp = solve(n - 1);

        // we have to append 0 in one round and then reverse temp and then append 1 in them -> see grey code example:
        vector<int> ans;
        for(int i=0; i<temp.size(); i++)
        {
            ans.push_back(temp[i]);
        }

        // reverse the temp vector and append one: You have to set nth bit -> if n = 3 then on 3rd bit:
        reverse(temp.begin(), temp.end());
        for(int i=0; i<temp.size(); i++)
        {
            int num = temp[i];
            int appendOneAtNthPlace = appendOne(num, n);
            ans.push_back(appendOneAtNthPlace);
        }

        return ans;
    }

    vector<int> grayCode(int n) {
        // Using Recursion:
        return solve(n);


        // Using bit manipulation:
        // vector<int> ans ((1 << n));

        // for(int i=0; i<(1<<n); i++)
        // {
        //     ans[i] = i ^ (i >> 1);
        // }

        // return ans;
    }
};