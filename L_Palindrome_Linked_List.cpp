class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // find mid of the linked list:
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next && fast -> next -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode* head2 = slow -> next; // second linked list head
        slow -> next = NULL; // first linked list termination

        // reverse second List:
        ListNode* prev = NULL;
        ListNode* curr = head2;
        
        while(curr) {
            ListNode* node = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = node;
        }

        head2 = prev; // making last node of the original linked list as the head of the second linked list

        // doing acc to question: building connections
        ListNode* temp = head;
        while(temp && head2) {
            if(temp -> val != head2 -> val) return false;
            temp = temp -> next;
            head2 = head2 -> next;
        }
        return true;
    }
};