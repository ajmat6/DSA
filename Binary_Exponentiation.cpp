#define ll long long 
const int mod = 1e9 + 7; 

// mod and long long might not be required acc to the question

int binaryExpo(ll x, int power) {
    ll ans = 1;
    while(power != 0) {
        if(power % 2) {
            ans = (ans * 1LL * x) % mod;
            power--;
        } 
        else {
            x = (x * 1LL * x) % mod;
            power /= 2;
        }
    }
    return ans;
}