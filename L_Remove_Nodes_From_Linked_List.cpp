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

    ListNode* removeNodes(ListNode* head) {
        // using stack:
        // stack<ListNode*> st;
        // ListNode* temp = head;
        // while(temp != NULL) {
        //     if(!st.empty()) {
        //         while(!st.empty() && st.top() -> val < temp -> val) st.pop();
        //     }
        //     st.push(temp);
        //     temp = temp -> next;
        // }

        // vector<ListNode*> ans;
        // while(!st.empty()) {
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // reverse(ans.begin(), ans.end());

        // ListNode* newHead = ans[0];
        // ListNode* tempo = newHead;
        // for(int i=1; i<ans.size(); i++) {
        //     tempo -> next = ans[i];
        //     tempo = tempo ->  next;
        // }

        // return newHead;



        // using reverse:
        ListNode* newHead = reverse(head);
        ListNode* temp = newHead -> next;
        ListNode* prev = newHead;

        while(temp != NULL) {
            if(temp -> val >= prev -> val) {
                prev -> next = temp;
                prev = temp;
            }
            temp = temp -> next;
        }
        prev -> next = NULL;
        return reverse(newHead);
    }
};