class Solution {
public:
    vector<int> Primes;
    void sieve(int N) {
        bool isPrime[N + 1];
        isPrime[0] = isPrime[1] = false;
        for(int i=2; i<N; i++) isPrime[i] = true;
        for(int i=2; i*i<N; i++) {
            if(isPrime[i]) {
                for(int j=i*i; j<N; j+=i) {
                    if(isPrime[j]) isPrime[j] = false;
                }
            }
        }

        for(int i=2; i<N; i++) {
            if(isPrime[i]) Primes.push_back(i);
        }
    }

    bool findPrime(int& num, int& nextNum) {
        int low = 0; 
        int ans = num;
        int high = Primes.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(num - Primes[mid] < nextNum) {
                ans = Primes[mid];
                high = mid - 1;
            }
            else low = mid + 1;
        }

        if(ans < num) {
            num -= ans;
            return true;
        }
        return false;
    }

    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        sieve(maxElement);
        int n = nums.size();
        for(int i=n-2; i>=0; i--) {
            if(nums[i] >= nums[i + 1] && !findPrime(nums[i], nums[i + 1])) return false;
        }
        return true;
    }
};