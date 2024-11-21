class Solution {
public:
    void findDivisorsFreq(vector<int>& nums, vector<int>& div) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            for(int j=1; j*j<=nums[i]; j++) {
                if(nums[i] % j == 0) {
                    div[j]++;
                    if(nums[i] / j != j) div[nums[i] / j]++;
                }
            }
        }
    }

    void findGCDCount(vector<int>& div) {
        int n = div.size();
        for(int i=0; i<n; i++) div[i] = (div[i] * 1LL * (div[i] - 1)) / 2; // nC2 find
    }

    void decreaseCount(vector<int>& div) {
        int n = div.size();
        for(int i=n-1; i>=1; i--) {
            for(int j=1; j*j<=i; j++) {
                if(j == i) continue;
                if(i % j == 0) {
                    div[j] -= div[i];
                    if(i / j != j && (i / j) != i) div[i / j] -= div[i];
                }
            }
        }
    }

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxElement = *max_element(nums.begin(), nums.end()); // N time
        vector<int> div (maxElement + 1, 0); // find array of highest gcd possible

        findDivisorsFreq(nums, div); // each poss divisor -> N * sqrt(maxElement) time
        findGCDCount(div); // each possible gcd count -> maxElement time
        decreaseCount(div); // subtract higher gcd no count from lower gcd no count -> maxElement * sqrt(maxElement) time

        // prfix sum
        int n = div.size();
        for(int i=1; i<n; i++) div[i] += div[i - 1]; // maxElement time

        // binary of search over gcd's:
        vector<int> ans;
        for(auto i: queries) { // q * log(maxElement) time
            int elementNo = i + 1;
            int index = lower_bound(div.begin(), div.end(), elementNo) - div.begin();
            ans.push_back(index);
        }
        return ans;
    }
};