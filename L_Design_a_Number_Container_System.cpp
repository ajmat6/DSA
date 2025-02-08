class NumberContainers {
private: unordered_map<int, int> indexValue;
         unordered_map<int, priority_queue<int, vector<int>, greater<int>>> valueIndex;
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if(indexValue.count(index) && indexValue[index] == number) return;
        indexValue[index] = number;
        valueIndex[number].push(index);
    }
    
    int find(int number) {
        if(valueIndex.count(number) == 0) return -1;
        auto& pq = valueIndex[number];
        while(!pq.empty() && indexValue[pq.top()] != number) pq.pop();
        return pq.empty() ? -1 : pq.top();
    }
};