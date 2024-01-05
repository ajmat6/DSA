class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        int index = 0;

        // closed at 0: Assuming to be closed at 0th hour
        for(int i=0; i<customers.size(); i++)
        {
            if(customers[i] == 'Y') penalty += 1;
        }

        int minPenalty = penalty;

        // checking closed shop at each index, keeping it opened at ith index and adding or reducing penalty at ith index customer presence or absence:
        for(int i=0; i<=customers.size(); i++)
        {
            if(customers[i] == 'Y')
            {
                penalty -= 1;
                if(penalty < minPenalty)
                {
                    index = i + 1;
                    minPenalty = penalty;
                }  
            }

            // if shop was opened till ith index and at ith index no customer come;
            else 
            {
                penalty += 1;
            }
        }

        return index;
    }
};