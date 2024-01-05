#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--)
    {
        ll n, totalPoints, lesson, task;
        cin >> n >> totalPoints >> lesson >> task;

        ll day = 8;
        int dayCount = 1;
        ll points = 0;

        // first I will add points of those days less than n where I will have two pending tasks:
        while(true)
        {
            if(day > n)
            {
                if(day - 7 <= n)
                {
                    points  += task + lesson;
                }
                else dayCount--;
                break;
            }

            else if(day == n)
            {
                points += 2 * task + lesson;
                break;
            }

            else
            {
                points += 2 * task + lesson;
                if(points >= totalPoints) break;
            }

            dayCount++;
            day += 14;
        }

        int rem = totalPoints - points;
        while(dayCount <= n)
        {
            if(rem <= 0) break;
            rem -= lesson;
            dayCount++;
        }

        cout << n - dayCount << "\n";
    }

    return 0;
}