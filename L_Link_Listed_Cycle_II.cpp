class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head  == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* start = head;

        while(fast -> next != NULL && fast -> next -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
            {
                while(start != slow)
                {
                    slow = slow -> next;
                    start = start -> next;
                }
                return start;
            }
        }

        return NULL;
    }
};