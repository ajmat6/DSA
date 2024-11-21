class Node {
    private: Node* links[2];
    public:
    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
    }
    
    bool containsKey(int key) {
        return links[key] != nullptr;
    }
    
    void put(int key, Node* node) {
        links[key] = node;
    }
    
    Node* get(int key) {
        return links[key];
    }
};

class Trie {
    private: Node* root;
    public:
    Trie() {
        root = new Node();
    }
    
    void insert(int num) {
        Node* temp = root;
        for(int i=31; i>=0; i--) {
            int bit = ((1 << i) & num) == 0 ? 0 : 1;
            if(!temp -> containsKey(bit)) temp -> put(bit, new Node());
            temp = temp -> get(bit);
        }
    }
    
    int maxXor(int num) {
        Node* temp = root;
        int ans = 0;
        for(int i=31; i>=0; i--) {
            int bit = ((1 << i) & num) == 0 ? 0 : 1;
            if(temp -> containsKey(!bit)) {
                temp = temp -> get(!bit);
                ans += pow(2, i);
            }
            else if(temp -> containsKey(bit)) temp = temp -> get(bit);
            else return ans;
        }
        return ans;
    }
};

class Solution {
  public:
    int maximumSumOfXorSums(int n, vector<int> &arr) {
        vector<int> prefixXor(n);
        vector<int> postXor(n);
        
        Trie t1;
        int currXor = 0;
        for(int i=0; i<n; i++) {
            currXor ^= arr[i];
            prefixXor[i] = max(currXor, t1.maxXor(currXor));
            if(i != 0) prefixXor[i] = max(prefixXor[i], prefixXor[i - 1]);
            t1.insert(currXor);
        }
        
        Trie t2;
        currXor = 0;
        for(int i=n-1; i>=0; i--) {
            currXor ^= arr[i];
            postXor[i] = max(currXor, t2.maxXor(currXor));
            if(i != n - 1) postXor[i] = max(postXor[i], postXor[i + 1]);
            t2.insert(currXor);
        }
        
        int ans = 0;
        for(int i=0; i<n-1; i++) {
            ans = max(ans, prefixXor[i] + postXor[i + 1]);
        }
        
        return ans;
    }
};