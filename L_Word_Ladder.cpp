class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // starting with beginWord with 1st level

        // making set for checking if word exist or not:
        unordered_set<string> s;
        for(auto i: wordList)
        {
            s.insert(i);
        }

        // Now as we push a word into the queue, it means we are taking that word from wordList. After taking any word remove that word from the set so that we dont take it afterwords:
        s.erase(beginWord);

        // BFS:
        while(!q.empty())
        {
            string word = q.front().first;
            int len = q.front().second;
            q.pop();

            // return current word found length if current word is the endWord:
            if(word == endWord) return len;

            for(int i=0; i<word.length(); i++)
            {
                string temp = word;
                for(int j=0; j<26; j++)
                {
                    temp[i] = 'a' + j; // changing current word ith character

                    // checking if that word exist in the queue or not:
                    if(s.find(temp) != s.end())
                    {
                        q.push({temp, len + 1}); // pushing into queue with 1 step increased
                        s.erase(temp); // erase found word from the queue
                    }
                }
            }
        }

        // if the function does not get returned above, it means target word does not exist in the wordList:
        return 0;
    }
};