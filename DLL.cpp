// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data) {
        this -> data = data;
        next = nullptr;
        back = nullptr;
    }
};

Node* createDLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    
    for(int i=1; i<5; i++) {
        Node* node = new Node(arr[i]);
        prev -> next = node;
        node -> back = prev;
        prev = prev -> next;
    }
    return head;
}

void printDLL(Node* head) {
    Node* prev = head;
    cout << "Printing from first to last:" << endl;
    while(prev -> next != NULL) {
        cout << prev -> data << " ";
        prev = prev -> next;
    }
    cout << prev -> data;

    cout << "\nPrinting from first to last:" << endl;
    while(prev) {
        cout << prev -> data << " ";
        prev = prev -> back;
    }
}

Node* deleteHead(Node* head) {
    if(!head || !head -> next) return nullptr;
    Node* temp = head;
    head = head -> next;
    head -> back = nullptr;
    temp -> next = nullptr;
    delete temp;
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    
    // create DLL:
    Node* head = createDLL(arr);
    
    // print DLL:
    printDLL(head);
    
    // delete head of DLL:
    cout << endl;
    Node* newHead = deleteHead(head);
    printDLL(newHead);

    return 0;
}