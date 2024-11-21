#include <bits/stdc++.h> 

class Node {
    Node* links[26];
    bool flag = false;
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

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
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
        }
        temp -> setEnd();
    }

    string find(string word) {
        Node* temp = root;
        for(int i=0; i<word.size(); i++) {
            temp = temp -> get(word[i]);
            if(!temp -> isEnd()) return "";
        }
        return word;
    }
};

string completeString(int n, vector<string> &a){
    Trie t;
    for(auto i: a) t.insert(i);

    string ans = "";
    for(auto i: a) {
        string temp = t.find(i);
        if(temp.size() > ans.size()) ans = temp;
        else if(temp.size() == ans.size() && temp < ans) ans = temp;
    }
    return ans == "" ? "None" : ans;
}