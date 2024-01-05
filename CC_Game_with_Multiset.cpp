#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; 
    cin >> t;

    unordered_map<int, int> mp;
    while(t--)
    {
        int a, b;
        cin >> a >> b;

        if(a == 1) mp[pow(2, b)]++;
        else
        {
            vector<pair<int, int>> temp;
            for(auto i: mp) temp.push_back({i.first, i.second});
            sort(temp.begin(), temp.end());
            reverse(temp.begin(), temp.end());

            if(b == 0)
            {
                cout << "YES\n";
                continue;
            }

            bool found = false;
            for(int i=0; i<temp.size(); i++)
            {
                if(temp[i].first <= b)
                {
                    int quo = b / temp[i].first;
                    int rem = b % temp[i].first;

                    if(quo <= temp[i].second && rem == 0)
                    {
                        found = true;
                        break;
                    }

                    else if(quo <= temp[i].second)
                    {
                        b = b - (temp[i].first * quo);
                    }

                    else 
                    {
                        b = b - (temp[i].first * temp[i].second);
                    }
                }
            }

            if(found) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}