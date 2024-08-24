class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head;
        ListNode* temp = head -> next;

        while(temp) {
            int sum = 0;
            while(temp && temp -> val != 0) {
                sum += temp -> val;
                temp = temp -> next;
            }
            temp = temp -> next;
            curr -> val = sum;
            if(!temp) curr -> next = nullptr;
            else curr = curr -> next;
        }
        return head;
    }
};