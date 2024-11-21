void MyQueue :: push(int x) {
    if(rear == 100004) return;
    arr[rear] = x;
    rear++;
}

int MyQueue :: pop() {
    if(front == rear) return -1;
    int ans = arr[front];
    front++;
    if(front == rear) {
        front = 0;
        rear = 0;
    }
    return ans;
}