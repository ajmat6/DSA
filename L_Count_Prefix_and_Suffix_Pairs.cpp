class Solution {
public:
    bool isPrefixSuffix(string& a, string& b) {
        if(b.find(a) == 0) {
            int j = a.size() - 1;
            for(int i=b.size() - 1; i>=0; i--) {
                if(a[j] == b[i]) {
                    j--;
                    if(j < 0) break;
                }
                else return false;
            }
            return true;
        }
        return false;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(isPrefixSuffix(words[i], words[j])) count++;
            }
        }
        return count;
    }
};




// using trie:
class Node {
    Node* links[26];
    int count;

    public:
    Node() {
        for(int i=0; i<26; i++) links[i] = nullptr;
        count = 0;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] == nullptr ? false : true;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setCount() {
        count++;
    }

    int getCount() {
        return count;
    }
};

class Trie {
    private: Node* root;
    public:
    Trie() {
        root = new Node();
    }

    int insertWord(string& word) {
        int n = word.size();
        Node* temp = root;
        int count = 0;
        for(int i=0; i<n; i++) {
            if(!temp -> containsKey(word[i])) temp -> put(word[i], new Node());
            temp = temp -> get(word[i]);

            // insert from last also at next trie node:
            if(!temp -> containsKey(word[n - i - 1])) temp -> put(word[n - i - 1], new Node());
            temp = temp -> get(word[n - i - 1]);

            count += temp -> getCount();
        }
        temp -> setCount();
        return count;
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        Trie t;
        for(int i=0; i<words.size(); i++) {
            count += t.insertWord(words[i]);
        }
        return count;
    }
};