// tc is klogk + nlogk where n are total elements and sc is k for priority_queue
class Node {
    public: 
        int val, row, col;
        Node(int data, int x, int y) {
            val = data;
            row = x;
            col = y;
        }
};

class cmp {
    public:
    bool operator()(Node* a, Node* b) {
        return a -> val > b -> val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();
        priority_queue<Node*, vector<Node*>, cmp> pq;

        for(int i=0; i<n; i++) {
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            Node* newNode = new Node(nums[i][0], i, 0);
            pq.push(newNode);
        }

        int ansStart = mini;
        int ansEnd = maxi;
        while(!pq.empty()) {
            Node* node = pq.top();
            pq.pop();

            int start = node -> val;
            int end = maxi;

            if(end - start < ansEnd - ansStart) {
                ansStart = start;
                ansEnd = end;
            }

            if(node -> col + 1 < nums[node -> row].size()) {
                maxi = max(maxi, nums[node -> row][node -> col + 1]);
                Node* newNode = new Node(nums[node -> row][node -> col + 1], node -> row, node -> col + 1);

                pq.push(newNode);
            }
            else break;
        }

        return {ansStart, ansEnd};
    }
};







// sc is n + k and tc is nlogn + 2n
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<pair<int, int>> temp;
        for(int i=0; i<n; i++) {
            for(auto j: nums[i]) temp.push_back({j, i});
        }

        int low = 0, high = 0;
        int minRange = INT_MAX;
        int ansStart = -1, ansEnd = -1;
        unordered_map<int, int> mp;
        sort(temp.begin(), temp.end());

        while(high < temp.size()) {
            mp[temp[high].second]++;

            while(mp.size() == n) {
                int currRange = temp[high].first - temp[low].first;
                if(currRange < minRange) {
                    minRange = currRange;
                    ansStart = temp[low].first;
                    ansEnd = temp[high].first;
                }
                mp[temp[low].second]--;
                if(mp[temp[low].second] == 0) mp.erase(temp[low].second);
                low++;
            }

            high++;
        }

        return {ansStart, ansEnd};
    }
};