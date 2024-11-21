// using hashmap and set: logn time and n space:
// class AllOne {
// private: unordered_map<string, int> mp;
//          set<pair<int, string>> st;
// public:
//     AllOne() {}
    
//     void inc(string key) {
//         mp[key]++;
//         int len = mp[key];
//         if(len != 1) st.erase({len - 1, key});
//         st.insert({len, key});
//     }
    
//     void dec(string key) {
//         int len = mp[key];
//         if(len == 1) mp.erase(key);
//         else mp[key]--;
//         st.erase({len, key});
//         if(len != 1) st.insert({len - 1, key});
//     }
    
//     string getMaxKey() {
//         if(st.size() == 0) return "";
//         return prev(st.end()) -> second;
//     }
    
//     string getMinKey() {
//         if(st.size() == 0) return "";
//         return st.begin() -> second;
//     }
// };




class Node {
public:
    int freq; // what is the freq value of this node:
    unordered_set<string> st; // contains strings or keys with same frequency:
    Node* next;
    Node* prev;
    Node(int val) : freq(val), next(nullptr), prev(nullptr) {}
};

class AllOne {
private: unordered_map<string, Node*> mp;
         Node* head;
         Node*  tail;
public:
    AllOne() {
        head = new Node(-1);
        tail = new Node(-1);
        head -> next = tail;
        tail -> prev = head;
    }

    void insert(Node* node, int f, string& key) {
        Node* newNode = new Node(f);
        newNode -> st.insert(key);
        Node* nextNode = node -> next;
        node -> next = newNode;
        newNode -> next = nextNode;
        newNode -> prev = node;
        nextNode -> prev = newNode;
        mp[key] = newNode;
    }

    void deleteNode(Node* node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        node -> next = nullptr;
        node -> prev = nullptr;
        delete node;
    }
    
    void inc(string key) {
        if(mp.count(key) == 0) {
            if(head -> next -> freq == 1) {
                head -> next -> st.insert(key);
                mp[key] = head -> next;
            }
            else insert(head, 1, key);
        }
        else {
            Node* prevNode = mp[key];
            int prevFreq = prevNode -> freq;
            prevNode -> st.erase(key);
            if(prevNode -> next -> freq == prevNode -> freq + 1) {
                prevNode -> next -> st.insert(key);
                mp[key] = prevNode -> next;
            }
            else insert(prevNode, prevFreq + 1, key);
            if(prevNode -> st.empty()) deleteNode(prevNode);
        }

    }
    
    void dec(string key) {
        Node* currNode = mp[key];
        currNode -> st.erase(key);

        if(currNode -> freq > 1) {
            if(currNode -> prev -> freq == currNode -> freq - 1) {
                currNode -> prev -> st.insert(key);
                mp[key] = currNode -> prev;
            }
            else insert(currNode -> prev, currNode -> freq - 1, key);
        }
        else mp.erase(key);
        if(currNode -> st.empty()) deleteNode(currNode);
    }
    
    string getMaxKey() {
        if(tail -> prev -> freq == -1) return "";
        return *(tail -> prev -> st.begin());
    }
    
    string getMinKey() {
        if(head -> next -> freq == -1) return "";
        return *(head -> next -> st.begin());
    }
};