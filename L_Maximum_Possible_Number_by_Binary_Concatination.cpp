class Solution {
public:
    string intToBinary(int num) {
        string ans = "";
        while(num != 0) {
            ans.push_back((num & 1) + '0');
            num /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int binaryToInt(string bin) {
        int n = bin.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(bin[i] == '1') ans += pow(2, n - i - 1); 
        }
        return ans;
    }

    static bool cmp(string& a, string& b)  {
        if(a + b > b + a) return true;
        return false;
    }

    int maxGoodNumber(vector<int>& nums) {
        // first generate binary representation of each number in nums
        vector<string> binary;
        for(auto i: nums) binary.push_back(intToBinary(i));


        // using sorting according string value:
        sort(binary.begin(), binary.end(), cmp);
        return binaryToInt(binary[0] + binary[1] + binary[2]);

        // using generating all permutation of combinations: total 6 possible:
        // return max({binaryToInt(binary[0] + binary[1] + binary[2]),
        //             binaryToInt(binary[0] + binary[2] + binary[1]),
        //             binaryToInt(binary[1] + binary[0] + binary[2]),
        //             binaryToInt(binary[1] + binary[2] + binary[0]),
        //             binaryToInt(binary[2] + binary[0] + binary[1]),
        //             binaryToInt(binary[2] + binary[1] + binary[0])
        //         });
    }
};