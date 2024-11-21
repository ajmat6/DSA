class Solution {
public:
    void insertInRight(int val, set<pair<int, int>>& right, set<pair<int, int>>& left, long long& sum, int& x, unordered_map<int, int>& mp) {
        mp[val]++;
        int oldFreq = mp[val] - 1;
        int newFreq = mp[val];

        if(right.find({oldFreq, val}) != right.end()) {
            sum -= (val * 1LL * oldFreq);
            right.erase({oldFreq, val});
            sum += (val * 1LL * newFreq);
            right.insert({newFreq, val});
            return;
        }

        if(newFreq == 1 && right.size() < x) {
            sum += (val * 1LL * newFreq);
            right.insert({newFreq, val});
            return;
        }

        // check in left existence:
        if(left.find({oldFreq, val}) != left.end()) left.erase({oldFreq, val});

        int rightFreq = right.begin() -> first;
        int rightVal = right.begin() -> second;
        if(newFreq > rightFreq || (newFreq == rightFreq && val > rightVal)) {
            sum -= (rightFreq * 1LL * rightVal);
            right.erase({rightFreq, rightVal});
            left.insert({rightFreq, rightVal});
            sum += (newFreq * 1LL * val);
            right.insert({newFreq, val});
        }

        else left.insert({newFreq, val});
    }

    void reduceFromRight(int val, set<pair<int, int>>& right, set<pair<int, int>>& left, long long& sum, int& x, unordered_map<int, int>& mp) {
        int oldFreq = mp[val];
        int newFreq = mp[val] - 1;
        mp[val]--;
        
        // check in right:
        if(right.find({oldFreq, val}) != right.end()) {
            sum -= (val * 1LL * oldFreq);
            right.erase({oldFreq, val});
            sum += (val * 1LL * newFreq);
            right.insert({newFreq, val});

            if(left.size() == 0) return;

            // check left set end element freq and val:
            int leftEndFreq = prev(left.end()) -> first;
            int leftEndVal = prev(left.end()) -> second;

            if(newFreq < leftEndFreq || (newFreq == leftEndFreq && leftEndVal > val)) {
                sum -= (val * 1LL * newFreq);
                sum += (leftEndVal * 1LL * leftEndFreq);
                right.erase({newFreq, val});
                left.insert({newFreq, val});
                left.erase({leftEndFreq, leftEndVal});
                right.insert({leftEndFreq, leftEndVal});
            }
            return;
        }

        // check in left if not find in right:
        left.erase({oldFreq, val});
        left.insert({newFreq, val});
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> mp;
        set<pair<int, int>> left, right;

        long long sum = 0;
        int n = nums.size();
        for(int i=0; i<k && i<n; i++) insertInRight(nums[i], right, left, sum, x, mp);

        int low = 0;
        int high = k - 1;
        vector<long long> ans;
        while(high < n) {
            ans.push_back(sum);
            reduceFromRight(nums[low], right, left, sum, x, mp);
            low++; high++;
            if(high < n) insertInRight(nums[high], right, left, sum, x, mp);
        }

        return ans;
    }
};