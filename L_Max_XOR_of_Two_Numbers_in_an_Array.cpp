class Node
{
    public:
    Node* links[2]; // as only two possible input 0 and 1

    bool containsKey(int bit)
    {
        if(links[bit] != NULL) return true;
        else return false;
    }

    void put(int bit, Node* node)
    {
        links[bit] = node;
    }

    Node* get(int bit)
    {
        return links[bit];
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

    void insert(int num)
    {
        Node* node = root;
        for(int i=31; i>=0; i--)
        {
            // we have to find ith bit that wheather it is 0 and 1:
            int bit = (num >> i) & 1; // finding bit value of ith bit in no:

            if(!node -> containsKey(bit))
            {
                node -> put(bit, new Node());
            }

            node = node -> get(bit);
        }
    }

    // function to find max value from XOR:
    int getMax(int num)
    {
        Node* node = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--)
        {
            int bit = (num >> i) & 1;

            // as we want to opposite bit to make max sum:
            if(node -> containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i); // will turn ith bit of maxNum on
                node = node -> get(1 - bit);
            }

            // if opposite bit is not available, move to the next bit:
            else
            {
                node = node -> get(bit);
            }

        }

        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;

        // inserting all nums in trie:
        for(int i=0; i<nums.size(); i++)
        {
            t.insert(nums[i]);
        }

        // finding max XOR:
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int temp = t.getMax(nums[i]);
            ans = max(ans, temp);
        }

        return ans;
    }
};