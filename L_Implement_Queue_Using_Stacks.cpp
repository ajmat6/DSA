// push efficient and better when no of push operation are larger as compared to peek and pop:
class MyQueue {
private: stack<int> st1, st2;
public:
    MyQueue() {}
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty()) { // stack 2 might have elements in the form of queue of previous push
            int ans = st2.top();
            st2.pop();
            return ans;
        }
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        int ans = st2.top();
        st2.pop();
        return ans;
    }
    
    int peek() {
        if(!st2.empty()) return st2.top();
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty() ? true : false;
    }
};




// when push operation are smaller as compared to peek and pop:
class MyQueue {
private: stack<int> mainSt;
         stack<int> helpSt;
public:
    MyQueue() {}
    
    void push(int x) {
        while(!mainSt.empty()) {
            helpSt.push(mainSt.top());
            mainSt.pop();
        }

        mainSt.push(x);
        while(!helpSt.empty()) {
            mainSt.push(helpSt.top());
            helpSt.pop();
        }
    }
    
    int pop() {
        int ans = mainSt.top();
        mainSt.pop();
        return ans;
    }
    
    int peek() {
        return mainSt.top();
    }
    
    bool empty() {
        return mainSt.empty();
    }
};