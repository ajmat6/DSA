// using array: O(1) time and n space
class MyCircularDeque {
private: int* arr;
         int front;
         int rear;
         int size;
public:
    MyCircularDeque(int k) {
        arr = new int[k];
        front = -1; 
        rear = -1;
        size = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;

        if(front == -1 || front == 0) front = size - 1;
        else front--;
        arr[front] = value;

        if(rear == -1) rear = size - 1;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;

        rear = (rear + 1) % size;
        arr[rear] = value;

        if(front == -1) front = 0;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        if(rear == front) rear = front = -1;
        else front = (front + 1) % size;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        if(front == rear) rear = front = -1;
        else if(rear == 0) rear = size - 1;
        else rear--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        else return arr[rear];
    }
    
    bool isEmpty() {
        if(front == -1) return true;
        return false;
    }
    
    bool isFull() {
        if((front == 0 && rear == size - 1) || (front - 1 == rear)) return true;
        return false;
    }
};




// using linked list: O(1) time and n space
class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this -> val = val;
        prev = nullptr;
        next = nullptr;
    }
};

class MyCircularDeque {
private: Node* head;
         Node* tail;
         int size;
         int currSize;
public:
    MyCircularDeque(int k) {
        head = new Node(-1);
        tail = new Node(-1);
        size = k;
        currSize = 0;

        head -> next = tail;
        tail -> prev = head;
    }

    void insertNode(Node* node, int val) {
        Node* nextNode = node -> next;
        Node* newNode = new Node(val);
        node -> next = newNode;
        newNode -> prev = node;
        nextNode -> prev = newNode;
        newNode -> next = nextNode;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node -> prev;
        Node* nextNode = node -> next;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
        delete node;
    }
    
    bool insertFront(int value) {
        if(currSize == size) return false;
        insertNode(head, value);
        currSize++;
        return true;
    }
    
    bool insertLast(int value) {
        if(currSize == size) return false;
        insertNode(tail -> prev, value);
        currSize++;
        return true;
    }
    
    bool deleteFront() {
        if(currSize == 0) return false;
        deleteNode(head -> next);
        currSize--;
        return true;
    }
    
    bool deleteLast() {
        if(currSize == 0) return false;
        deleteNode(tail -> prev);
        currSize--;
        return true;
    }
    
    int getFront() {
        if(currSize == 0) return -1;
        return head -> next -> val;
    }
    
    int getRear() {
        if(currSize == 0) return -1;
        return tail -> prev -> val;
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == size;
    }
};