class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;

        // counting size of the LL:
        int size = 0;
        ListNode* temp = head;

        while(temp != NULL)
        {
            size++;
            temp = temp -> next;
        }

        // calculating size of each part and extra remainder:
        int onePartSize = size / k;
        int rem = size % k;

        // pointers to track each parted LL:
        temp = head;
        ListNode* nextpointer = head;
        int count = 0;

        while(temp != NULL)
        {
            ListNode* tempHead = temp;
            int times = onePartSize;

            // if onepart size is greater than zero:
            if(times != 0)
            {
                // taking temp to last node a split list:
                while(times > 1)
                {
                    temp = temp -> next;
                    times--;
                }

                // if there is some extra node in each list(if there is remainder):
                if(rem > 0)
                {
                    temp = temp -> next;
                    rem--;
                }
            }

            // this will work for both cases: when k is greater than size and vice versa:
            nextpointer = temp -> next;
            temp -> next = NULL;
            temp = nextpointer;
            ans.push_back(tempHead);
            count++;
        }

        // if k > size and no of parted lists are less than k:
        if(count < k)
        {
            for(; count<k; count++)
            {
                ans.push_back(NULL);
            }
        }

        return ans;
    }
};