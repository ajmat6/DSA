class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // ex2 and ex3 cases:
        if(head == NULL || head -> next == NULL) return head;

        // pointers to track:
        ListNode* temp1 = head;
        ListNode* temp2 = head -> next;

        // first swap for head node
        temp1 -> next = temp2 -> next;
        temp2 -> next = temp1;
        head = temp2;

        // prev node track:
        ListNode* prev = temp1;

        // for next interation shifting of pointers:
        temp1 = temp1 -> next;
        if(temp1) temp2 = temp1 -> next;
        else temp2 = NULL;

        while(temp2 != NULL)
        {
            // swapping:
            temp1 -> next = temp2 -> next;
            temp2 -> next = temp1;
            prev -> next = temp2;
            prev = temp1;

            // for next itration, shifting of pointers:
            temp1 = temp1 -> next;
            if(temp1) temp2 = temp1 -> next;
            else temp2 = NULL;
        }

        return head;
    }
};