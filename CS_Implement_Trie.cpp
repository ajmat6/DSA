/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

 struct Node
 {
     Node* links[26];
     bool flag = false;

     public:

     Node() {}
     bool containsKey(char ch)
     {
         // if the character is present in our trie formation:
         if(links[ch - 'a'] != NULL) return true;
         else return false;
     }

     void put(char ch, Node* node)
     {
         links[ch - 'a'] = node;
     }

     Node* get(char ch)
     {
         return links[ch - 'a'];
     }

     void setEnd()
     {
         flag = true;
     }

    // to tell if current word has ended or not while searching:
     bool isEnd()
     {
        return flag;
     }
 };


class Trie {
private:
    Node* root;

public:

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            // if curr char is not in links:
            if(!node -> containsKey(word[i]))
            {
                node -> put(word[i], new Node()); // if current char does not exist then create a new node and insert word:
            }

            // now move to the created reference trie:
            node = node -> get(word[i]);
        }

        // here word length is over, so setting up end of the trie:
        node -> setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            // if current char does not exist:
            if(!node -> containsKey(word[i])) return false;

            // if present then reaching to that node:
            node = node -> get(word[i]);
        }

        // at end we have to check that last node flag is true or not:
        return node -> isEnd();
    }2

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.size(); i++)
        {
            if(!node -> containsKey(prefix[i])) return false;

            node = node -> get(prefix[i]);
        }

        // while prefix check there  is no need to check end of the word:
        return true;
    }
};