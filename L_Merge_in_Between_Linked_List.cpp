class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        int count = 1;
        while(count < a) {
            temp = temp -> next;
            count++;
        }
        ListNode* temp2 = temp -> next;
        temp -> next = list2;

        while(count <= b) {
            temp2 = temp2 -> next;
            count++;
        }
        while(list2 -> next) list2 = list2 -> next;
        list2 -> next = temp2;
        return list1;
    }
};