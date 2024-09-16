class Solution {
public:
    bool check(int num1, int num2) {
        vector<int> freq1 (10);
        vector<int> freq2 (10);

        string s1 = to_string(num1);
        string s2 = to_string(num2);
        int n1 = s1.size(); int n2 = s2.size();

        if(s1.size() != s2.size()) {
            string temp = "";
            int rem = abs(n1 - n2);
            for(int i=0; i<rem; i++) temp += '0';
            if(n1 < n2) {
                temp += s1;
                s1 = temp;
            }
            else {
                temp += s2;
                s2 = temp;
            }
        }

        for(int i=0; i<s1.size(); i++) {
            freq1[s1[i] - '0']++;
            freq2[s2[i] - '0']++;
        }

        // check for freq:
        bool poss = true;
        for(int i=0; i<10; i++) {
            if(freq1[i] != freq2[i]) {
                poss = false;
                break;
            }
        }

        if(poss) {
            int count = 0;
            for(int i=0; i<s1.size(); i++) {
                if(s1[i] != s2[i]) count++;
            }

            if(count <= 2) return true;
            else return false;
        }
        else return false;
    }

    int countPairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
               if(check(nums[i], nums[j])) ans++;
            }
        }
        return ans;
    }
};