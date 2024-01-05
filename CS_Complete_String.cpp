#include <bits/stdc++.h> 

struct Node
{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
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

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    Node* root;

    public:
    Trie()
    {
        root = new Node();
    }

    void insert(string& word)
    {
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(!node -> containsKey(word[i]))
            {
                node -> put(word[i], new Node());
            }

            node = node -> get(word[i]);
        }

        node -> setEnd();
    }

    bool prefixExist(string& word)
    {
        Node* node = root;
        for(int i=0; i<word.size(); i++)
        {
            if(node -> containsKey(word[i]))
            {
                // reaching to that trie and it should be a end trie (flag marked as true):
                node = node -> get(word[i]);
                if(node -> isEnd() == false) return false;
            }

            // if trie does not contain a char return false:
            return false;
        }

        return true;
    }
};

string completeString(int n, vector<string> &a){
    Trie* t;

    // insert string words into the trie:
    for(int i=0; i<n; i++)
    {
        t -> insert(a[i]);
    }

    string longest = "";

    // iterating over each word and checking for its prefix:
    for(int i=0; i<n; i++)
    {
        // if all prefix of word exist:
        if(t -> prefixExist(a[i]) == true)
        {
            // if word size is greater than longest:
            if(a[i].size() > longest.size()) longest = a[i];
            
            // if word size is equal to longest and is lexicographically smaller than longest:
            else if(a[i].size() == longest.size() && a[i] < longest)
            {
                longest = a[i];
            }
        }
    }

    if(longest == "") return "None";
    else return longest;
}