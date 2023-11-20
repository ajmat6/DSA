#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;

ll solve(ll num)
{
    ll total = 0;
    if(x > 10) total += 10;
    else return num;

    string s = to_string(num);
    ll len = s.size();
    string temp = s.substr(1, s.size() - 1);
    ll middle = stoi(temp);
    string first;
    first  += s[0];
    int firstDigit = stoi(first);

    for(int i=1; i<=9; i++)
    {
        for(int j=0; j<len-1; j++)
        {
            if(j < len - 2) total += pow(10, i);
            else if(j == len - 2 && i < firstDigit) total += pow(10, i);
            else if (j == len - 2 && i == firstDigit) total += middle;
            else total += 1;
        }
    }

    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll l, r;
    cin >> l >> r;

    int left = solve(l - 1);
    int right = solve(r);

    cout << right - left << "\n";

    return 0;
}