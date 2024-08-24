// #include<bits/stdc++.h>
// using namespace std;

// class Queue {
//     int* arr;
//     int front;
//     int rear;
//     int size;
    
//     public:
//     Queue(int n) {
//       size = n;
//       rear = -1;
//       front = -1;
//       arr = new int[size];
//     }
    
//     ~Queue() {
//         delete []arr;
//     }
    
//     bool isEmpty() {
//       if(front == -1) return true;
//       else return false;
//     }
    
//     bool isFull() {
//       if((front == 0 && rear == size - 1) || (rear == front - 1)) return true;
//       else return false;
//     }
    
//     void enqueue(int data) {
//       if(isFull()) {
//         cout << "Queue is Full!\n";
//         return;
//       }
//       if(front == -1) {
//         front = 0;
//         rear = 0;
//       }
//       else rear = (rear + 1) % size;
//       arr[rear] = data;
//     }
    
//     void dequeue() {
//       if(isEmpty()) {
//         cout << "No Elements to Pop!\n";
//         return;
//       }
//       int ans = arr[front];
//       if(front == rear) {
//         front = -1;
//         rear = -1;
//       }
//       else front = (front + 1) % size;
//       cout << ans << " Poped from queue!\n";
//     }
    
//     void frontElement() {
//       if(isEmpty()) cout << "No elements in queue!\n";
//       else cout << "Front Element is: " << arr[front] << endl;
//     }
    
//     void printQueue() {
//       if(isEmpty()) {
//         cout << "No elements to print!\n";
//         return;
//       }
      
//       cout << "Printing Queue: ";
//       int index = front;
//       if(rear < front) {
//         for(int i=index; i<size; i++) cout << arr[i] << " ";
//         for(int i=0; i<=rear; i++) cout << arr[i] << " ";
//       }
//       else for(int i=index; i<=rear; i++) cout << arr[i] << " ";
//       cout << "\n";
//     }
// };

// int main() {
//   Queue q(8);
  
//   vector<int> nums = {20, 1, 2, 4, 5};
//   for(int i=0; i<nums.size(); i++) {
//     q.enqueue(nums[i]);
//   }
//   q.printQueue();
//   q.dequeue();
//   q.printQueue();
//   q.dequeue();
//   q.printQueue();
//   q.frontElement();
//   q.enqueue(100);
//   q.printQueue();
  
//   for(int i=0; i<nums.size(); i++) {
//     q.enqueue(nums[i]);
//   }
//   q.printQueue();
//   q.dequeue();
//   q.printQueue();
//   q.enqueue(500);
//   q.enqueue(1000);
//   q.printQueue();
  
//   while(!q.isEmpty()) q.dequeue();
  
//   return 0;
// }



// dequeue concept added:
#include<bits/stdc++.h>
using namespace std;

class Queue {
    int* arr;
    int front;
    int rear;
    int size;
    
    public:
    Queue(int n) {
      size = n;
      rear = -1;
      front = -1;
      arr = new int[size];
    }
    
    ~Queue() {
        delete []arr;
    }
    
    bool isEmpty() {
      if(front == -1) return true;
      else return false;
    }
    
    bool isFull() {
      if((front == 0 && rear == size - 1) || (rear == front - 1)) return true;
      else return false;
    }
    
    void enqueue(int data) {
      if(isFull()) {
        cout << "Queue is Full!\n";
        return;
      }
      if(front == -1) {
        front = 0;
        rear = 0;
      }
      else rear = (rear + 1) % size;
      arr[rear] = data;
    }
    
    void enqueueFront(int data) {
      if(isFull()) {
        cout << "Queue is Full!\n";
        return;
      }
      if(front == -1) {
        front = 0;
        rear = 0;
      }
      else if(front == 0) front = size - 1;
      else front--;
      arr[front] = data;
    }
    
    void dequeue() {
      if(isEmpty()) {
        cout << "No Elements to Pop!\n";
        return;
      }
      int ans = arr[front];
      if(front == rear) {
        front = -1;
        rear = -1;
      }
      else front = (front + 1) % size;
      cout << ans << " Poped from queue!\n";
    }
    
    void dequeueBack() {
      if(isEmpty()) {
        cout << "No Elements to Pop!\n";
        return;
      }
      int ans = arr[rear];
      if(front == rear) {
        front = -1;
        rear = -1;
      }
      else if(rear == 0) rear = size - 1;
      else rear--;
      cout << ans << " Poped from queue!\n";
    }
    
    void frontElement() {
      if(isEmpty()) cout << "No elements in queue!\n";
      else cout << "Front Element is: " << arr[front] << endl;
    }
    
    void printQueue() {
      if(isEmpty()) {
        cout << "No elements to print!\n";
        return;
      }
      
      cout << "Printing Queue: ";
      int index = front;
      if(rear < front) {
        for(int i=index; i<size; i++) cout << arr[i] << " ";
        for(int i=0; i<=rear; i++) cout << arr[i] << " ";
      }
      else for(int i=index; i<=rear; i++) cout << arr[i] << " ";
      cout << "\n";
    }
};

int main() {
  Queue q(8);
  
  // vector<int> nums = {20, 1, 2, 4, 5};
  // for(int i=0; i<nums.size(); i++) {
  //   q.enqueue(nums[i]);
  // }
  // q.printQueue();
  // q.dequeue();
  // q.printQueue();
  // q.dequeueBack();
  // q.printQueue();
  // q.frontElement();
  // q.enqueueFront(100);
  // q.printQueue();
  
  // for(int i=0; i<nums.size(); i++) {
  //   q.enqueue(nums[i]);
  // }
  // q.printQueue();
  // q.dequeueBack();
  // q.printQueue();
  // q.enqueueFront(500);
  // q.enqueue(1000);
  // q.printQueue();
  
  // while(!q.isEmpty()) q.dequeue();
  
  int a;
  cout << a;
  
  return 0;
}