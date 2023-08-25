/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int gcd(int a, int b)
    {
        if(a == b) return a;
        if(a > b) return gcd(a-b, b);
        else return gcd(a, b-a);
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
//         if(head -> next == NULL) 
//         {
//             ListNode* newNode = new ListNode(head -> val);
//             head -> next = newNode;
//             return head;
//         }
        
        ListNode* temp1 = head;
        ListNode* temp2 = head -> next;
        
        while(temp2 != NULL)
        {
            int common = gcd(temp1 -> val, temp2 -> val);
            
            ListNode* newNode = new ListNode(common);
            temp1 -> next = newNode;
            newNode -> next = temp2;
            
            // shifting of nodes:
            temp2 = temp2 -> next;
            temp1 = newNode -> next;
        }
        
        return head;
    }
};