class Node {
    Node* links[26];
    int countPrefix = 0;
    public:
    Node() {
        for(int i=0; i<26; i++) links[i] = nullptr;
    }

    ~Node() {
        for(int i=0; i<26; i++) delete links[i];
    }
    
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void increasePrefix() {
        countPrefix++;
    }

    int getPrefix() {
        return countPrefix;
    }
};

class Trie {
    private: Node* root;
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
            temp -> increasePrefix();
        }
    }

    int find(string word) {
        int count = 0;
        Node* temp = root;
        for(int i=0; i<word.size(); i++) {
            temp = temp -> get(word[i]);
            count += temp -> getPrefix();
        }
        return count;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        // Gives TLE: using hashmap: n * m time and n * m space:
        // unordered_map<string, int> mp;
        // for(auto i: words) {
        //     string temp = "";
        //     for(int j=0; j<i.size(); j++) {
        //         temp += i[j];
        //         mp[temp]++;
        //     }
        // }

        // vector<int> ans;
        // for(auto i: words) {
        //     string temp = "";
        //     int count = 0;
        //     for(int j=0; j<i.size(); j++) {
        //         temp += i[j];
        //         count += mp[temp];
        //     }
        //     ans.push_back(count);
        // }
        // return ans;


        // using trie: n * m time but with no string operation overhead
        Trie t;
        for(auto i: words) t.insert(i);

        vector<int> ans;
        for(auto i: words) {
            ans.push_back(t.find(i));
        }
        return ans;
    }
};