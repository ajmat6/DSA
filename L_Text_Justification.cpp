class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        // pointers to track first and last word in one line:
        int i = 0;
        int j;

        while(i < words.size())
        {
            int wc = words[i].size(); // word count will count actual words length in one line
            j = i + 1;
            int spaces = 0;

            // present words count length + min spaces + next word size if less, then include next word:
            while(j < words.size() && wc + spaces + words[j].size() + 1 <= maxWidth)
            {
                wc += words[j].size();
                spaces += 1;
                j++;
            }

            // till here one line words are there
            // j will be on word next of the line becoz of j++
            // int minSpaces = j - i - 1;
            int availableSpaces = maxWidth - wc; // max spaces available to us

            int oneSpace = spaces == 0 ? 0 : availableSpaces / spaces; // if there is only one word in the line for ex in case of acknowledgement, so only one word so no sense of spaces b/w words and extra spaces b/w words
            int extraSpace = spaces == 0 ? 0 : availableSpaces % spaces;

            // if current line is last line:
            if(j == words.size())
            {
                oneSpace = 1;
                extraSpace = 0;
            }

            // forming one line of ans string:
            string temp = "";
            for(int k=i; k<j; k++)
            {
                temp += words[k];

                if(k == j-1) break; // last word in one line:

                // append spaces
                for(int l=0; l<oneSpace; l++)
                {
                    temp += " "; // adding max common spaces b/w each word
                }

                // appending extra spaces if avialable:
                if(extraSpace > 0)
                {
                    temp += " ";
                    extraSpace--;
                }
            }

            // now if the length of one line string is less than maxWidth (in case like acknowledgement__) we have to append spaces at the end:
            while(temp.size() < maxWidth) temp += " ";

            ans.push_back(temp); // adding current line to ans
            i = j; 
        }

        return ans;
    }
};