class Node {
    public:
    pair<int,int> data;
    Node* left;
    Node* right;
    Node(pair<int, int> x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class MyCalendar {
private: Node* root;
        vector<pair<int, int>> nums;
        map<int, int> mp;
public:
    MyCalendar() {
        root = nullptr;
    }

    bool insertIntoTree(int start, int end) {
        Node* temp = root;
        while(temp) {
            if(start > temp -> data.first && start >= temp -> data.second) {
                if(temp -> right) temp = temp -> right;
                else {
                    Node* newNode = new Node({start, end});
                    temp -> right = newNode;
                    return true;
                }
            }
            else if(start < temp -> data.first && end <= temp -> data.first) {
                if(temp -> left) temp = temp -> left;
                else {
                    Node* newNode = new Node({start, end});
                    temp -> left = newNode;
                    return true;
                }
            }
            else return false;
        }

        return true;
    }
    
    bool book(int start, int end) {
        // using storing in arrays: n time and n space for each query:
        // for(auto &i: nums) {
        //     int s = i.first;
        //     int e = i.second;

        //     if((start > s && start >= e) || (start < s && end <= s)) {}
        //     else return false;
        // }
        // nums.push_back({start, end});
        // return true;



        // using binary search in maps: logn time and n space:
        auto ptr = mp.lower_bound(start);
        if(ptr != mp.end() && ptr -> first < end) return false;
        if(ptr != mp.begin() && start < prev(ptr) -> second) return false;
        mp[start] = end;
        return true;



        // using bst: logn time and n space:
        // if(root == nullptr) {
        //     root = new Node({start, end});
        //     return true;
        // }

        // return insertIntoTree(start, end);
    }
};