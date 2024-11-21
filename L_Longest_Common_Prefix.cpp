class Node {
private: Node* links[26];
         int count = 0;
public: 
    Node() {
        for(int i=0; i<26; i++) links[i] = nullptr;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* getNode(char ch) {
        return links[ch - 'a'];
    }

    void inCount() {
        count++;
    }

    int getCount() {
        return count;
    }
};

class Solution {
private: Node* root = new Node();
public:
    void insert(string word) {
        Node* temp = root;
        for(int i=0; i<word.size(); i++) {
            if(!temp -> containsKey(word[i])) return;
            temp = temp -> getNode(word[i]);
            temp -> inCount();
        }
    }

    string longestCommonPrefix(vector<string>& s) {
        // using trie: time is n * m and space is length of first word of s:
        // Node* temp = root;
        // string firstWord = s[0];
        // for(int i=0; i<firstWord.size(); i++) {
        //     if(!temp -> containsKey(firstWord[i])) temp -> put(firstWord[i], new Node());
        //     temp = temp -> getNode(firstWord[i]);
        //     temp -> inCount();
        // }

        // int n = s.size();
        // for(int i=1; i<n; i++) insert(s[i]);

        // temp = root;
        // string ans = "";
        // for(int i=0; i<firstWord.size(); i++) {
        //     temp = temp -> getNode(firstWord[i]);
        //     int count = temp -> getCount();
        //     if(count != n) return ans;
        //     else ans.push_back(firstWord[i]);
        // }
        // return ans;



        // using greedy:
        sort(s.begin(), s.end());
        int n = s.size();
        string ans = "";
        string first = s[0]; string last = s[n - 1];
        for(int i=0; i<min(first.size(), last.size()); i++) {
            if(first[i] != last[i]) break;
            ans += first[i];
        }
        return ans;
    }
};