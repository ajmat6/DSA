class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(head != NULL) {
            next = head -> next;
            head -> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    int solve(ListNode* head) {
        if(head == NULL) return 0;

        int value = ((head -> val) * 2 + solve(head -> next));
        head -> val = value % 10;
        return value / 10;
    }

    ListNode* doubleIt(ListNode* head) {
        // // reverse the linked list:
        // ListNode* newHead = reverse(head);

        // // double the linked list:
        // ListNode* temp = newHead;
        // ListNode* nextt = NULL;
        // int carry = 0;
        // while(temp != NULL) {
        //     int value = (temp -> val * 2) + carry;
        //     temp -> val = value % 10;
        //     carry = value / 10;
        //     nextt = temp;
        //     temp = temp -> next;
        // }

        // if(carry != 0) {
        //     ListNode* node = new ListNode(carry);
        //     nextt -> next = node;
        // }

        // // again reverse the linked list:
        // return reverse(newHead);



        // using recursion:
        // int carry = solve(head);
        // if(carry != 0) {
        //     ListNode* newNode = new ListNode(carry);
        //     newNode -> next = head;
        //     return newNode;
        // }
        // return head;



        // using Math:
        ListNode* temp = head;
        if(head -> val > 4) {
            ListNode* newHead = new ListNode(1);
            newHead -> next = head;
            head = newHead;
            temp = head -> next;
        }

        while(temp != NULL) {
            int carry = 0;
            if(temp -> next != NULL && temp -> next -> val > 4) carry = 1;
            temp -> val = ((temp -> val) * 2 + carry) % 10;
            temp = temp -> next;
        }

        return head;
    }
};