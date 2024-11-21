class Node {
    Node* links[10];
    public:
    Node() {
        for(int i=0; i<10; i++) links[i] = nullptr; // not initializing then with nullptr will give runtime error
    }

    ~Node() {
        for(int i=0; i<10; i++) delete links[i];
    }

    bool containsKey(char ch) {
        return links[ch - '0'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - '0'] = node;
    }

    Node* get(char ch) {
        return links[ch - '0'];
    }
};

class Trie {
    Node* root;
    public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        delete root;
    }

    void insert(string word) {
        Node* temp = root;
        for(int i=0; i<word.size(); i++) {
            if(!temp -> containsKey(word[i])) temp -> put(word[i], new Node());
            temp = temp -> get(word[i]);
        }
    }

    int prefix(string word) {
        Node* temp = root;
        int len = 0;
        for(int i=0; i<word.size(); i++) {
            if(!temp -> containsKey(word[i])) return len;
            temp = temp -> get(word[i]);
            len++;
        }
        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // Trie t;
        // for(int i=0; i<arr1.size(); i++) t.insert(to_string(arr1[i]));
        // int ans = 0;
        // for(auto i: arr2) ans = max(ans, t.prefix(to_string(i)));
        // return ans;


        // using hashmap: n * length of word + m * length of word is time complexity and n space:
        unordered_map<int, int> mp;
        for(auto i:arr1) {
            int num = i;
            // storing every prefix of every element of arr:
            while(num > 0) {
                mp[num]++;
                num /= 10;
            }
        }

        int ans = 0;
        for(auto i: arr2) {
            // checking every prefix of every element of arr2:
            int num = i;
            int len = log10(num) + 1;
            while(num != 0) {
                if(mp.find(num) != mp.end()) break;
                num /= 10;
                len--;
            }

            ans = max(ans, len);
        }
        return ans;
    }
};