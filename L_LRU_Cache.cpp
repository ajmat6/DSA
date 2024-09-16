class LRUCache {
    unordered_map<int, int> mp;
    unordered_map<int, int> trackTime;
    set<pair<int, int>> st;
    int size;
    int time;
public:
    LRUCache(int capacity) {
        size = capacity;
        time = 0;
    }
    
    int get(int key) {
        if(mp.count(key) == 0) return -1;

        // find the time of the key in set and delete it:
        st.erase({trackTime[key], key});
        trackTime[key] = time;
        st.insert({time, key});
        time++;
        return mp[key];
    }
    
    void put(int key, int value) {
        // update if already there:
        if(mp.count(key) != 0) {
            st.erase({trackTime[key], key});
            mp[key] = value;
            trackTime[key] = time;
            st.insert({time, key});
            time++;
        }

        // new key:
        else {
            if(size == 0) {
                auto timeKey = *st.begin();
                st.erase(st.begin());
                mp.erase(timeKey.second); // second is key and first is time
                trackTime.erase(timeKey.second);
                size += 1;
            }

            // insert:
            mp[key] = value;
            trackTime[key] = time;
            st.insert({time, key});
            size--;
            time++;
        }
    }
};




// using linked list:
class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this -> key = key;
        this -> val = val;
        next = nullptr;
        prev = nullptr;
    }
};

void deleteNode(Node* node) {
    Node* prevNode = node -> prev;
    Node* nextNode = node -> next;
    prevNode -> next = nextNode;
    nextNode -> prev = prevNode;
}

void insertAtHead(Node* node, Node* head) {
    Node* headNext = head -> next;
    node -> next = headNext;
    node -> prev = head;
    head -> next = node;
    headNext -> prev = node;
}

class LRUCache {
    Node* head;
    Node* tail;
    int size;
    unordered_map<int, Node*> mp;
public:
    LRUCache(int capacity) {
        size = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mp.count(key) == 0) return -1;
        Node* node = mp[key];
        mp.erase(key); // as there will new reference:
        deleteNode(node);
        insertAtHead(node, head);
        mp[key] = head -> next;
        return node -> val;
    }
    
    void put(int key, int value) {
        // if already there:
        Node* node;
        if(mp.count(key) != 0) {
            node = mp[key];
            node -> val = value;
            mp.erase(key);
            deleteNode(node);
        }

        else {
            if(mp.size() == size) {
                Node* temp = tail -> prev;
                mp.erase(tail -> prev -> key);
                deleteNode(tail -> prev);
                delete temp;
            }

            node = new Node(key, value);
        }
        insertAtHead(node, head);
        mp[key] = head -> next;
    }
};