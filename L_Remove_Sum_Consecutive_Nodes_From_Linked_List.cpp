class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head; 
        unordered_map<int, ListNode*> mp;
        ListNode* temp = dummy;
        int sum = 0;
        while(temp) {
            sum += temp -> val;
            mp[sum] = temp;
            temp = temp -> next;
        }

        temp = dummy; sum = 0;
        while(temp) {
            sum += temp -> val;
            temp -> next = mp[sum] -> next;
            temp = temp -> next;
        }

        // if zero came then dummy changed otherwise dummy will remain same:
        head = dummy -> next;
        return head;
    }
};