class Node
{
	Node* links[26];
    bool flag = false;
	
	public:
	bool containskey(char ch)
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

bool dfs(Node* node, int index, string& word)
{
    // if(isFound == true) return;
    if(index == word.size())
    {
        if(node -> isEnd()) return true;
        else return false;
    }

    if(word[index] == '.')
    {
        for(char i='a'; i<='z'; i++)
        {
            if(node -> containskey(i))
            {
                bool temp = dfs(node -> get(i), index + 1, word);
                if(temp) return true;
            }
        }

        return false;
    }

    else
    {
        if(node -> containskey(word[index]))
        {
            return dfs(node -> get(word[index]), index + 1, word);
        }

        else return false;
    }

    return false;
}

class WordDictionary 
{
    Node* root;

    public:
    WordDictionary() 
    {
        root = new Node();
    }
    
    void addWord(string word) 
    {
        Node* node = root;
		for(int i=0; i<word.size(); i++)
		{
			if(!node -> containskey(word[i]))
			{
				node -> put(word[i], new Node());
			}

			node = node -> get(word[i]);
		}

        node -> setEnd();
    }
    
    bool search(string word) 
    {
        Node* node = root;
        return dfs(node, 0, word);
    }
};