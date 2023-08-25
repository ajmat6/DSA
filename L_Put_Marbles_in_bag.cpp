class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // Using Heaps for tracking min and max Scores:
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // as cost of the bag include adjacent partition indexes, adding each pair and pushing them into the heap:
        for(int i=1; i<weights.size(); i++)
        {
            maxHeap.push(weights[i] + weights[i-1]);
            if(maxHeap.size() == k) maxHeap.pop();

            minHeap.push(weights[i] + weights[i-1]);
            if(minHeap.size()== k) minHeap.pop();
        }

        // as there are k-1 adjacent indexes:
        long long diff = 0;
        while (!minHeap.empty()) {
            diff += minHeap.top() - maxHeap.top();
            minHeap.pop(); 
            maxHeap.pop();
        }

        return diff;
    }
};
