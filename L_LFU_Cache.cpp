class Node {
public:
    int freq;
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int freq, int key, int val): freq(freq), key(key), val(val), next(nullptr), prev(nullptr) {}
};

class List {
public:
    Node* head;
    Node* tail;
    int size;

    List() {
        head = new Node(0, -1, -1);
        tail = new Node(0, -1, -1);
        head -> next = tail;
        tail -> prev = head;
        size = 0;
    }

    // new node inserted at tail:
    void insertNode(Node* newNode) {
        tail -> prev -> next = newNode;
        newNode -> prev = tail -> prev;
        newNode -> next = tail;
        tail -> prev = newNode;
        size++;
    }

    // deletion of node in freqList:
    void deleteNode(Node* node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        node -> next = nullptr;
        node -> prev = nullptr;
        size--;
        delete node;
    }
};

class LFUCache {
private: unordered_map<int, Node*> keyNode;
         unordered_map<int, List*> freqList;
         int minFreq;
         int size = 0;
public:
    LFUCache(int capacity) {
        size = capacity;
        minFreq = 0;
    }

    void updateNode(Node* node) {
        int prevFreq = node -> freq;
        int newFreq = prevFreq + 1;

        keyNode.erase(node -> key);
        Node* newNode = new Node(newFreq, node -> key, node -> val);
        keyNode[newNode -> key] = newNode;

        freqList[prevFreq] -> deleteNode(node);
        if(freqList[prevFreq] -> size == 0) {
            freqList.erase(prevFreq);
            if(minFreq == prevFreq) minFreq++;
        }

        List* currList;
        if(freqList.count(newFreq)) currList = freqList[newFreq];
        else currList = new List();
        freqList[newFreq] = currList;
        currList -> insertNode(newNode);
    }
    
    int get(int key) {
        if(keyNode.count(key) == 0) return -1;

        Node* currNode = keyNode[key];
        int val = currNode -> val;
        updateNode(currNode);
        return val;
    }
    
    void put(int key, int value) {
        if(keyNode.count(key)) {
            Node* currNode = keyNode[key];
            currNode -> val = value;
            updateNode(currNode);
            return;
        }

        else if(size == 0) {
            List* list = freqList[minFreq];
            keyNode.erase(list -> head -> next -> key);
            list -> deleteNode(list -> head -> next);
        }

        else size--;
    
        minFreq = 1;
        Node* newNode = new Node(1, key, value);
        keyNode[key] = newNode;

        List* currList;
        if(freqList.count(minFreq)) currList = freqList[minFreq];
        else currList = new List();
        freqList[minFreq] = currList;
        currList -> insertNode(newNode);
    }
};

