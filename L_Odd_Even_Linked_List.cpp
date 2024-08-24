class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* curr = head;
        ListNode* headNext = head -> next;
        ListNode* nextt = head -> next;

        while(nextt != NULL && nextt -> next != NULL) {
            curr -> next = nextt -> next;
            curr = curr -> next;
            nextt -> next = curr -> next;
            nextt = nextt -> next;
        }
        curr -> next = headNext;
        return head;
    }
};