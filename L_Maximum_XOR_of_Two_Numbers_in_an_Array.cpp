class Node {
private: 
    Node* links[2];

public:
    bool isPointing(int bit) {
        if(links[bit] == nullptr) return false;
        else return true;
    }

    void createTrieNode(int bit, Node* node) {
        links[bit] = node;
    }

    Node* goToNode(int bit) {
        return links[bit];
    }
};

class Trie {
private: Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int n) {
        Node* temp = root;
        for(int i=31; i>=0; i--) {
            int bit = (n >> i) & 1;
            if(!temp -> isPointing(bit)) temp -> createTrieNode(bit, new Node());
            temp = temp -> goToNode(bit);
        }
    }

    int findXorr(int& n) {
        Node* temp = root;
        int maxXor = 0;
        for(int i=31; i>=0; i--) {
            int bit = (n >> i) & 1;
            if(temp -> isPointing(1 - bit)) {
                maxXor |= (1 << i);
                temp = temp -> goToNode(!bit);
            }
            else if(temp -> isPointing(bit)) temp = temp -> goToNode(bit);
            else break;
        }

        return maxXor;
    }
};

// main function:
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        int n = nums.size();

        // insert into Trie:
        for(int i=0; i<n; i++) {
            t.insert(nums[i]);
        }

        // check for every nums value max xor:
        int ans = INT_MIN;
        for(auto &i: nums) {
            ans = max(ans, t.findXorr(i));
        }

        return ans;
    }
};