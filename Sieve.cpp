// always adjust N isPrime, spf and Primes according to question:
const int N = 1e6;
vector<bool> isPrime;
vector<int> spf;
vector<int> Primes;
void sieve(int N) {
    isPrime.resize(N + 1);
    spf.resize(N + 1);
    Primes.resize(0);

    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<N; i++) {
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
    for(int i=2; i<N; i++) {
        if(isPrime[i]) Primes.push_back(i);
    }
}