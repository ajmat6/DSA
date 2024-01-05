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

    ll v, e;
    cin >> v >> e;

    vector<vector<int>> edges (e, vector<int> (2, 0));
    for(int i=0; i<e; i++) cin >> edges[i][0] >> edges[i][1];

    unordered_map<int, list<int>> adjList;
    for(auto i: edges)
    {
        adjList[i[0]].push_back(i[1]);
        adjList[i[1]].push_back(i[0]);
    }

    vector<int> colour (v + 1, 0);
    queue<int> q;
    q.push(1);
    colour[1] = 1;
    int flag = 0;

    while(!q.empty())
    {
        int front = q.front();
        int baapColour = colour[front];
        q.pop();

        for(auto i: adjList[front])
        {
            if(colour[i] == 0)
            {
                colour[i] = baapColour == 1 ? -1 : 1;
                q.push(i);
            }

            else
            {
                if(colour[i] == baapColour)
                {
                    // cout << "NO" << "\n";
                    flag = 1;
                    break;
                }
            }
        }

        if(flag == 1) break;
    }

    if(flag == 1)
    {
        cout << "NO";
    }

    else
    {
        // here we will have two groups, one having one typw of colour and other having diff colour:
        set<int> in;
        set<int> out;

        for(int i=1; i<colour.size(); i++)
        {
            if(colour[i] == 1) in.insert(i);
            else out.insert(i);
        }

        string ans = "";
        for(auto i: edges)
        {
            int u = i[0];
            int v = i[1];

            if(in.find(u) == in.end()) ans.push_back('0');
            else ans.push_back('1');
        }

        cout << "YES\n";
        cout << ans;
    }

    return 0;
}