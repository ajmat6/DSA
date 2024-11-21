#include <bits/stdc++.h> 
struct Node
{
    Node* links[26];
    int countWords = 0;
    int countPrefix = 0;

    Node(){}
    
    bool containsKey(char ch)
    {
        if(links[ch - 'a'] != NULL) return true;
        else return false;
    }

    // insert node if not exists:
    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }

    // get a node:
    Node* get(char ch)
    {
        return links[ch - 'a'];
    }

    // increase word count:
    void increaseWord()
    {
        countWords++;
    }

    // increase prefix count:
    void increasePrefix()
    {
        countPrefix++;
    }

    // to know no of words:
    int getWords()
    {
        return countWords;
    }

    // to know no of times a char is present there:
    int getPrefix()
    {
        return countPrefix;
    }

    // to reduce word count:
    void deleteWord()
    {
        countWords--;
    }

    // to reduce a char count:
    void reducePrefix()
    {
        countPrefix--;
    }
};

class Trie{
    Node* root;

    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node -> containsKey(word[i]))
            {
                node -> put(word[i], new Node());
            }

            // reaching to the trie of current word character:
            node = node -> get(word[i]);

            // and incresing its prefix count:
            node -> increasePrefix();
        }

        // once whole word is inserted, increase the word count in last trie:
        node -> increaseWord();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            // if curr char exist then reach to its trie:
            if(node -> containsKey(word[i]))
            {
                node = node -> get(word[i]);
            }

            // else return 0:  no words
            else return 0;
        }   

        return node -> getWords();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(node -> containsKey(word[i]))
            {
                node = node -> get(word[i]);
            }

            else return 0;
        }

        // will return no of words starting with "word":
        return node -> getPrefix();
    }

    void erase(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(node -> containsKey(word[i]))
            {
                node = node -> get(word[i]);
                node -> reducePrefix(); // reducing the prefix of each char in the word to be deleted
            }

            // if the word to be deleted does not exist:
            else return;
        }

        // reducing the word count at last trie of word:
        node -> deleteWord();
    }
};
