class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        
        for(int i=0; i<words.size(); i++)
        {
            string temp = words[i]; // checking for each of the string word in words
            int index = 0; // tracking seperator previous index
            
            for(int j=0; j<temp.size(); j++)
            {
                // check for final index:
                if(j == temp.size()-1 && temp[j] != separator)
                {
                    string sub = temp.substr(index, j - index + 1);
                    ans.push_back(sub);
                }
                
                else if(temp[j] == separator)
                {
                    string sub = temp.substr(index, j-index);
                    if(index != j)
                    {
                        ans.push_back(sub);
                    }
                    index = j + 1;
                }
            }
        }
        
        return ans;
    }
};