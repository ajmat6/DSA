class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // finding left and prev of left:
        if(left == 1 && right == 1) return head;

        ListNode* prev;
        ListNode* lefty = head;
        ListNode* righty = head;

        int i = 1;
        if(left == 1) prev = NULL;
        else
        {
            prev = head;
            lefty = lefty -> next;
            i++;
            while(i<left && lefty != NULL)
            {
                lefty = lefty -> next;
                prev = prev -> next;
                i++;
            }
        }

        int j = 1;
        while(j < right)
        {
            righty = righty -> next;
            j++;
        }

        ListNode* nextt = righty -> next;

        // reversing list:
        ListNode* previous = NULL;
        ListNode* curr = lefty;
        ListNode* nexty = lefty -> next;

        ListNode* firstTrack = curr;

        while(curr != righty)
        {
            curr -> next = previous;
            previous = curr;
            curr = nexty;
            
            if(nexty != NULL) nexty = nexty -> next;
        }

        curr -> next = previous;
        previous = curr;
        // curr = nexty;

        if(prev != NULL) prev -> next = curr;
        else head = curr;

        firstTrack -> next = nextt;

        return head;
    }
};