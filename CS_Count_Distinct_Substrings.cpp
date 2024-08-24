#include<bits/stdc++.h>
using namespace std;

class Node {
    private: 
    Node* links[26];

    public:
    bool isPointing(char ch) {
        if(links[ch - 'a'] == nullptr) return false;
        else return true;
    }

    void createTrieNode(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* goToNode(char ch) {
        return links[ch - 'a'];
    }
};

class Trie {
    private: Node* root;

    public:
    Trie() {
        root = new Node;
    }

    int insert(string& s) {
        int count = 0;
        Node* temp = root;
        for(int i=0; i<s.size(); i++) {
            if(!temp -> isPointing(s[i])) {
                temp -> createTrieNode(s[i], new Node);
                count += 1;
            } 
            temp = temp -> goToNode(s[i]);
        }

        return count;
    }
};

int countDistinctSubstrings(string &s){
    Trie t;
    int ans = 0;
    int n = s.size();
    for(int i=0; i<n; i++) {
        string sub = s.substr(i, n - i);
        ans += t.insert(sub);
    }
    return ans + 1;
}