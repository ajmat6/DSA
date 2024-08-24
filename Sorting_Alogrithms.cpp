#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int>& arr) {
    for(auto i: arr) cout << i << " ";
    cout << endl;
}

int main() {
    // vector<int> arr = {20, 4, 100, 67, 34, 2, 200};
    // int size = arr.size();
    
    
    // // bubble sort: n^2 TC and const SC
    // for(int i=0; i<size-1; i++) {
    //     for(int j=0; j<size-1-i; j++) {
    //         if(arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
    //     }
    // }
    // printArray(arr);
    
    
    // // insertion sort: n^2 TC and const SC
    // for(int i=1; i<arr.size(); i++) {
    //     int curr = i;
    //     int val = arr[curr]; 
    //     while(curr > 0 && val < arr[curr - 1]) {
    //         arr[curr] = arr[curr - 1];
    //         curr = curr - 1;
    //     }
    //     arr[curr] = val;
    // }
    // printArray(arr);
    
    
    // selection sort: n^2 TC and const SC
    // int putIndex = 0;
    // for(int i=0; i<size-1; i++) {
    //     int mini = INT_MAX; int minIndex = -1;
    //     for(int j=putIndex; j<size; j++) {
    //         if(arr[j] < mini) {
    //             mini = arr[j];
    //             minIndex = j;
    //         }
    //     }
        
    //     swap(arr[putIndex], arr[minIndex]);
    //     putIndex++;
    // }
    // printArray(arr);
    
    
    

    return 0;
}