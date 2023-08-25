class Solution {
public:
    bool buddyStrings(string s, string goal) {
        // Base cases:
        if(s.size() != goal.size()) return false;
        if(s.size() == 1) return false;

        // Checking if s and goal are equal or not:
        vector<int> arr (26, 0);
        int flag = 1;
        if(s != goal)
        {
            flag = 0;
        }

        // if equal then finding the frequency of each of the element:
        if(flag == 1)
        {
            // finding frequency:
            for(int i=0; i<s.size(); i++)
            {
                arr[s[i] - 'a']++;
            }

            // checking if all the elements in s are same alphabet:
            int count = 0;
            for(int i=0; i<arr.size(); i++)
            {
                if(arr[i] > 0) count++;
            }

            // if not same alphabet checking the frequency:
            if(count > 1)
            {
                for(int i=0; i<arr.size(); i++)
                {
                    if(arr[i] > 1) return true;
                }

                return false;
            }
        }

        // if s and goal are not equal:
        for(int i=0; i<s.size(); i++)
        {
            int flag = 1;
            if(s[i] == goal[i]) continue;

            else
            {
                for(int j=i+1; j<s.size(); j++)
                {
                    if(s[j] == goal[i] && s[j] != goal[j])
                    {
                        swap(s[i], s[j]);
                        flag = 0;
                        break;
                    }
                }
            }

            if(flag == 0) break;
        }

        if(s == goal) return true;

        return false;
    }
};