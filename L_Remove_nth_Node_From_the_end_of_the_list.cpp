class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if(head -> next == NULL) return NULL;

        ListNode* temp1 = head;
        ListNode* temp2 = head;
        int count = 0;

        // making a diff of n+1 b/w temp1 and temp2 node:
        while(temp1 != NULL)
        {
            temp1 = temp1 -> next;

            // if n+1 diff is created then increase temp2 node:
            if(count == n + 1)
            {
                temp2 = temp2 -> next;
                continue;
            }

            // counting to make diff of n+1:
            count++;
        }

        // if the node to be deteleted is head node:
        if(count < n + 1)
        {
            head = head -> next;
            delete temp2;
            return head;
        }

        // if the node to be deleted is any node other than head node:
        ListNode* temp = temp2 -> next;
        temp2 -> next = temp -> next;
        delete temp;
        return head;
    }
};