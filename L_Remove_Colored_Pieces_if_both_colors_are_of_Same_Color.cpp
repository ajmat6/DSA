class Solution {
public:
    bool winnerOfGame(string colors) {
        int bob = 0;
        int alice = 0;
        string b = "BBB";
        string a = "AAA";

        if(colors.size() < 3) return false;

        string temp = colors.substr(0, 3);
        if(temp == b) bob++;
        if(temp == a) alice++;

        for(int i=3; i<colors.size(); i++)
        {
            temp = temp.substr(1, 2);
            temp.push_back(colors[i]);

            if(temp == b) bob++;
            if(temp == a) alice++;
        }

        while(alice != 0 && bob != 0)
        {
            alice--;
            bob--;
        }

        return alice == 0 ? false : true;
    }
};