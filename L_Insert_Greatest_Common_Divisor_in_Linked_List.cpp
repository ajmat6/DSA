class Solution {
public:
    int findGCD(int a, int b) {
        if(b == 0) return a;
        return findGCD(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head -> next;
        while(second != nullptr) {
            int gcdd = findGCD(first -> val, second -> val);
            ListNode* newNode = new ListNode(gcdd);
            first -> next = newNode;
            newNode -> next = second;
            first = second;
            second = second -> next;
        }
        return head;
    }
};