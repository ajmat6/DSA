class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // string ans = "";
        // unordered_map<string, string> adjList;
        // for(auto i: paths)
        // {
        //     adjList[i[0]] = i[1];
        // }

        // string start = paths[0][0];
        // queue<string> q;
        // q.push(start);

        // while(!q.empty())
        // {
        //     string front = q.front();
        //     q.pop();

        //     if(adjList.find(front) == adjList.end()) 
        //     {
        //         ans = front;
        //         break;
        //     }
        //     else q.push(adjList[front]);
        // }

        // return ans;

        string ans = "";
        string start = paths[0][0];

        while(true)
        {
            bool found = true;
            for(auto i: paths)
            {
                if(i[0] == start)
                {
                    start = i[1];
                    found = false;
                    break;
                }
            }

            if(found) break;
        }

        return start;
    }
};