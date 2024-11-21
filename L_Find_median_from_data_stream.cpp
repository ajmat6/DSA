class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> mini; // second half of the array
    priority_queue<int> maxi; // first half of the array
    int size1, size2;
    MedianFinder() {
        size1 = 0;
        size2 = 0;
    }
    
    void addNum(int num) {
        if(size1 == 0 || num <= maxi.top()) {
            maxi.push(num);
            size1++;
        }
        else {
            mini.push(num);
            size2++;
        }

        // check no of elements in them:
        if(size1 - size2 > 1) {
            mini.push(maxi.top());
            size2++;
            maxi.pop();
            size1--;
        }

        if(size2 > size1) {
            maxi.push(mini.top());
            size1++;
            mini.pop();
            size2--;
        }
    }
    
    double findMedian() {
        if(size1 == size2) return (mini.top() + maxi.top()) / 2.0;
        return maxi.top();
    }
};