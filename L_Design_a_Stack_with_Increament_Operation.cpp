class CustomStack {
private: vector<int> arr;
         vector<int> inc;
         int maxSize;
         int currSize = 0;
public:
    CustomStack(int maxSize) {
        arr.resize(maxSize);
        inc.resize(maxSize, 0);
        this -> maxSize = maxSize;
    }
    
    void push(int x) {
        if(currSize == maxSize) return;
        arr[currSize] = x;
        currSize++;
    }
    
    int pop() {
        if(currSize == 0) return -1;
        int ans = arr[currSize - 1];
        ans += inc[currSize - 1]; // add increment

        if(currSize - 1 != 0) inc[currSize - 2] += inc[currSize - 1]; // add curr index inc to prev index
        inc[currSize - 1] = 0; // making curr inc to 0 as it is popped now
        currSize--;
        return ans;
    }
    
    // O(1) increment:
    void increment(int k, int val) {
        if(currSize == 0) return;
        int index = min(k, currSize);
        inc[index - 1] += val;
    }
};



// using linked list:
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* prev;
//     Node(int val) {
//         this -> val = val;
//         next = nullptr;
//         prev = nullptr;
//     }
// };

// class CustomStack {
// private: Node* head;
//          Node* tail;
//          int maxSize;
//          int currSize;
// public:
//     CustomStack(int maxSize) {
//         head = nullptr;
//         tail = nullptr;
//         this -> maxSize = maxSize;
//         currSize = 0;
//     }
    
//     void push(int x) {
//         if(currSize == maxSize) return;
//         currSize++;
//         Node* newNode = new Node(x);
//         if(!head) {
//             head = newNode;
//             tail = newNode;
//         }
//         else {
//             tail -> next = newNode;
//             newNode -> prev = tail;
//             tail = newNode;
//         }
//     }
    
//     int pop() {
//         if(currSize == 0) return -1;
//         currSize--;
//         int ans = tail -> val;
//         Node* prevNode = tail -> prev;
//         if(prevNode) prevNode -> next = nullptr;
//         else head = nullptr;
//         tail -> prev = nullptr;
//         Node* temp = tail;
//         tail = prevNode;
//         delete temp;
//         return ans;
//     }
    
//     void increment(int k, int val) {
//         if(currSize == 0) return;
//         int times = min(k, currSize);
//         Node* temp = head;
//         while(times > 0) {
//             temp -> val += val;
//             temp = temp -> next;
//             times--;
//         }
//     }
// };