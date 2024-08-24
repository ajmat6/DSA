class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& sand) {
        // using queue:
        queue<int> q;
        vector<int> count (2);

        for(auto i: s) {
            count[i]++;
            q.push(i);
        }

        int curr = 0;
        while(!q.empty()) {
            int front = q.front();
            if(front == sand[curr]) {
                curr++;
                count[front]--;
                q.pop();
            }

            else {
                if(count[sand[curr]] == 0) return q.size();
                else {
                    q.pop(); q.push(front);
                }
            }
        }

        return 0;

        // without queue:
        // vector<int> count (2, 0);
        // for(auto i: s) count[i]++;

        // int ans = sand.size();
        // for(auto i: sand) {
        //     if(count[i] == 0) return ans;
        //     count[i]--;
        //     ans--;
        // }
        // return 0;
    }
};