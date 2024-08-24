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
    
    bool isEmpty() {
      if(front == -1) return true;
      else return false;
    }
    
    bool isFull() {
      if(rear == size - 1) return true;
      else return false;
    }
    
    void enqueue(int data) {
      if(isFull()) cout << "Queue is Full!\n";
      else {
        if(front == - 1) {
          front = 0;
          rear = 0;
        }
        else rear++;
        arr[rear] = data;
      }
    }
    
    void dequeue() {
      if(isEmpty()) cout << "No Elements to Pop!\n";
      
      int ans = arr[front];
      if(front == rear) {
        front = -1;
        rear = -1;
      }
      else front++;
      
      cout << ans << " Poped from queue!\n";
    }
    
    void frontElement() {
      if(isEmpty()) cout << "No elements in queue!\n";
      else cout << "Front Element is: " << arr[front] << endl;
    }
    
    void printQueue() {
      if(isEmpty()) cout << "No elements to print!\n";
      int index = front;
      for(int i=index; i<=rear; i++) cout << arr[i] << " ";
      cout << "\n";
    }
};

int main() {
  Queue q(8);
  
  vector<int> nums = {20, 1, 2, 4, 5};
  for(int i=0; i<nums.size(); i++) {
    q.enqueue(nums[i]);
  }
  q.printQueue();
  q.dequeue();
  q.printQueue();
  q.dequeue();
  q.printQueue();
  q.frontElement();
  q.enqueue(100);
  q.printQueue();
  
  for(int i=0; i<nums.size(); i++) {
    q.enqueue(nums[i]);
  }
  q.printQueue();
  
  return 0;
}