#include <bits/stdc++.h>
using namespace std;

long long countt = 0;
void merge(long long *arr, int low, int mid, int high) {
    vector<int> temp;

    // array from low to mid is first array and from mid + 1 to high is second array:
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            countt += mid - left + 1;
            right++;
        } 
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++) {
        arr[i] = temp[i - low];
    }

    return;
}

void mergeSort(long long *arr, int low, int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
        return;
    }
    return;
} 

long long getInversions(long long *arr, int n){
    mergeSort(arr, 0, n-1);
    return countt;
}