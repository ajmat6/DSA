#include <bits/stdc++.h>
using namespace std;

int constructSegmentTree(int low, int high, int index, vector<int>& tree, int* arr)
{
    // Base case:
    if(low == high)
    {
        tree[index] = arr[low];
        return tree[index];
    }
    
    int mid = (low + high) / 2;
    tree[index] = constructSegmentTree(low, mid, 2 * index + 1, tree, arr) + constructSegmentTree(mid + 1, high, 2 * index + 2, tree, arr);
    return tree[index];
}

int main() \
{
	int arr[5] = {10, 20, 30, 40, 50};
	int size = 5;
	
	vector<int> tree (4 * size, -1);
	constructSegmentTree(0, 4, 0, tree, arr);
	for(auto i: tree)
	{
	    cout << i << " ";
	}
	
	return 0;
}