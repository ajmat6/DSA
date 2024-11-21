class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    long long lcm(long long a, long long b) {
        return (a * 1LL * b) / gcd(a, b);
    }
    
    long long findArrayGCD(vector<int>& arr) {
        long long result = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            result = gcd(result, arr[i]);
        }
        return result;
    }
    
    long long findArrayLCM(const vector<int>& arr) {
        long long result = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            result = lcm(result, arr[i]);
        }
        return result;
    }

    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0] * nums[0];
        
        long long ans = 0;
        ans = findArrayGCD(nums) * findArrayLCM(nums);
        
        for(int i=0; i<nums.size(); i++) {
            vector<int> temp;
            for(int j=0; j<nums.size(); j++) {
                if(j == i) continue;
                else temp.push_back(nums[j]);
            }
        
            if(temp.size() >= 1) {
                ans = max(ans, findArrayGCD(temp) * findArrayLCM(temp));
            }
        }
        return ans;
    }
};