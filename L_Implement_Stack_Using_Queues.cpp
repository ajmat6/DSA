// 1 queue:
class MyStack {
private: queue<int> q1;
public:
    MyStack() {}
    
    void push(int x) {
        q1.push(x);
        int size = q1.size();
        for(int i=0; i<size-1; i++) {
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};



// 2 queue:
class MyStack {
private: queue<int> q1, q2;
public:
    MyStack() {}
    
    void push(int x) {
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};