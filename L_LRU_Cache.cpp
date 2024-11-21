// using hashmaps: logn time for each
class LRUCache {
private: unordered_map<int, int> keyValue;
         unordered_map<int, int> keyTimer;
         map<int, int> timerKey;
         int size;
         int timer;
public:
    LRUCache(int capacity) {
        size = capacity;
        timer = 0;
    }
    
    int get(int key) {
        if(keyValue.count(key) == 0) return -1;

        int prevTime = keyTimer[key];
        timerKey.erase(prevTime);

        keyTimer[key] = timer;
        timerKey[timer] = key;
        timer++;

        return keyValue[key];
    }
    
    void put(int key, int value) {
        if(keyValue.count(key) != 0) {
            int prevTime = keyTimer[key];
            timerKey.erase(prevTime);
        }
        else if(size != 0) size--;
        else {
            int lruKey = timerKey.begin() -> second;
            int lruTime = timerKey.begin() -> first;
            timerKey.erase(lruTime);
            keyValue.erase(lruKey);
            keyTimer.erase(lruKey);
        }
        
        keyValue[key] = value;
        keyTimer[key] = timer;
        timerKey[timer] = key;
        timer++;
    }
};





// using doubly linked list: O(1) time for each case:
class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key, int val): key(key), value(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private: unordered_map<int, Node*> mp;
         Node* head;
         Node* tail;
         int size;
public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
        size = capacity;
    }

    // new node inserted at tail:
    void insertNode(int key, int val) {
        Node* newNode = new Node(key, val);
        tail -> prev -> next = newNode;
        newNode -> prev = tail -> prev;
        newNode -> next = tail;
        tail -> prev = newNode;
        mp[key] = newNode;
    }

    // deletion of node in DLL and in hashmap:
    void deleteNode(Node* node) {
        mp.erase(node -> key);
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        node -> next = nullptr;
        node -> prev = nullptr;
        delete node;
    }
    
    int get(int key) {
        if(mp.count(key) == 0) return -1;

        int val = mp[key] -> value;
        deleteNode(mp[key]);
        insertNode(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.count(key) != 0) deleteNode(mp[key]);
        else if(size != 0) size--;
        else deleteNode(head -> next);
        insertNode(key, value);
    }
};