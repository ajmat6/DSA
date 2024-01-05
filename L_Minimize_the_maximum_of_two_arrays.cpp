typedef long long ll;
class Solution {
public:
    int minimizeSet(int div1, int div2, int uc1, int uc2) {
        ll low = 1;
        ll high = INT_MAX;
        ll ans = INT_MAX;

        while(low <= high)
        {
            ll mid = low + (high - low) / 2;

            // no of nos till mid that are div by div1 and div2:
            ll x = mid / div1;
            ll y = mid / div2;

            // no of nos that are not div by div1 and div2:
            ll first = mid - x;
            ll second = mid - y;

            // no of nos that are div by both div1 and div2:
            ll hcf = gcd(div1, div2);
            ll lcm = (div1 * 1LL * div2) / hcf;
            ll both = mid / lcm;

            // no of nos that are not div by both div1 and div2:
            ll third = mid - (x + y - both);

            if(first >= uc1 && second >= uc2 && (first + second - third) >= (uc1 + uc2))
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        return ans;
    }
};