class MinStack {
private: stack<long long> st;
         long long mini = 0;
public:
    MinStack() {}
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        }
        else if(val < mini) {
            st.push(2 * 1LL * val - mini);
            mini = val;
        }
        else st.push(val);
    }
    
    void pop() {
        if(st.top() < mini) {
            // go to prevmin element;
            mini = 2 * 1LL * mini - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < mini) return mini;
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};





class Node {
public:
    pair<int, int> data;
    Node* next;
    Node(int val, int mini) {
        data.first = val;
        data.second = mini;
        next = nullptr;
    }
};

class MinStack {
private: Node* head; // pointing to top element in stack:
public:
    MinStack() {
        head = new Node(-1, INT_MAX);
    }
    
    void push(int val) {
        Node* newNode = new Node(val, min(head -> data.second, val));
        newNode -> next = head;
        head = newNode;
    }
    
    void pop() {
        Node* nextNode = head -> next;
        head -> next = nullptr;
        delete head;
        head = nextNode;
    }
    
    int top() {
        return head -> data.first;
    }
    
    int getMin() {
        return head -> data.second;
    }
};





class MinStack {
public:
    vector<int> arr;
    vector<int> index;

    MinStack() {}
    
    void push(int val) {
        if(index.empty() || val < arr[index.back()])
            index.push_back(arr.size());
        arr.push_back(val);
    }
    
    void pop() {
        arr.pop_back();
        if(index.back() == arr.size())
            index.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return arr[index.back()];
    }
};





class MinStack {
private: vector<pair<int, int>> st;
public:
    MinStack() {}
    
    void push(int val) {
        int minElem = 0;
        if(st.empty() || val < st.back().second) minElem = val;
        else minElem = st.back().second;
        st.push_back({val, minElem});
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};