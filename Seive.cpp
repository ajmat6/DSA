const int N = 1e7 + 10; // N can be any amount of nos to check in a range
vector<bool> isPrime (N, true);
vector<int> spf(N, 1); // spf is smallest prime factor of a number:

int main() {
    isPrime[0] = isPrime[1] = false;
    for(int i=1; i<N; i++) spf[i] = i;
    for(int i=2; i*i<N; i++) {
        if(isPrime[i] == true) {
            for(int j=i*i; j<N; j+=i) {
                if(isPrime[j]) {
                    isPrime[j] = false;
                    spf[j] = i;
                }
            }
        }
    }
}

// aryan mittal code snippet:
const ll N = 1e5 + 10;
ll isPrime[N];
ll spf[N];

void seive() {
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<=N; i++) {
        isPrime[i] = true;
        spf[i] = i;
    }

    for(int i=2; i*i<N; i++) {
        if(isPrime[i]) {
            for(int j=i*i; j<N; j+=i) {
                if(isPrime[j]) {
                    isPrime[j] = false;
                    spf[j] = i;
                }
            }
        }
    }
}

vi getAllPrimes(ll n) {
    unordered_map<ll, ll> mp;
    while(n != 1) {
        mp[spf[n]]++;
        n = n / spf[n];
    }

    vll ans;
    for(auto i: mp) ans.pb(i.F);
    return ans;
}