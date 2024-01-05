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
    if(num > 10) total += 9;
    else return num;

    string s = to_string(num);
    ll len = s.size();
    string temp = s.substr(1, s.size() - 2);

    ll middle;
    if(temp.size() == 0) middle = 0;
    else middle = stoi(temp);
    
    string first = s.substr(0, 1);
    int firstDigit = stoi(first);
    
    string last = s.substr(s.size() - 1, 1);
    int lastDigit = stoi(last);

    for(int i=1; i<=firstDigit; i++)
    {
        for(int j=0; j<len-1; j++)
        {
            if(j <= len - 2 && i < firstDigit) total += pow(10, j);
            else if (j == len - 2 && i == firstDigit) total += middle;
            else if (j == len - 2 && i == firstDigit && i <= lastDigit) total += 1;
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

    if(r < 10) return r - l + 1;

    int left = solve(l - 1);
    int right = solve(r);
    
    // cout << left << " " << right << " ";

    cout << right - left << "\n";

    return 0;
}