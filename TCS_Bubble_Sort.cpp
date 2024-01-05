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
    cout.tie(NULL);

    string input1, input2;
    getline(cin, input1);
    getline(cin, input2);
    

    stringstream ss1(input1), ss2(input2);

    vector<int> a1, a2;

    int num;
    while (ss1 >> num) {
        a1.push_back(num);
    }

    while (ss2 >> num) {
        a2.push_back(num);
    }

    int n = a1.size();
    bool isSorted;
    for(int i=0; i<n-1; i++)
    {
        isSorted = true;
        for(int j=0; j<n-1-i; j++)
        {
            if(a1[j] > a1[j+1])
            {
                int temp = a1[j];
                a1[j] = a1[j+1];
                a1[j+1] = temp;

                // making changes in a2:
                temp = a2[j];
                a2[j] = a2[j+1];
                a2[j+1] = temp;

                isSorted = false;
            }
        }

        if(isSorted) break;
    }

    for(int i=0; i<n; i++)
    {
        cout << a2[i];
        if(i != n-1) cout << " ";
    }
    
    return 0;
}