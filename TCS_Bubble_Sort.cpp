#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<pii> vpii;
int a1[1000];
int a2[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    vector<int> a1;

    getline(cin, input);

    stringstream ss(input);
    int num;
    while (ss >> num) {
        a1.push_back(num);
    }

    string input2;
    vector<int> a2;

    getline(cin, input2);

    stringstream ss2(input2);
    int num2;
    while (ss2 >> num2) {
        a2.push_back(num2);
    }

    int n = a1.size();
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<(n-1-i); j++)
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
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << a2[i] << " ";
    }

    return 0;
}