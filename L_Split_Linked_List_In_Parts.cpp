class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // traverse linked list
        int totalNodes = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            totalNodes++;
            temp = temp -> next;
        }

        int quo = totalNodes / k;
        int rem = totalNodes % k;
        vector<ListNode*> ans;

        temp = head;
        for(int i=0; i<k; i++) {
            int times = quo;
            if(rem != 0) {
                times += 1;
                rem--;
            }

            ListNode* prev = temp;
            while(times != 1 && temp != nullptr) {
                temp = temp -> next;
                times -= 1;
            }

            ans.push_back(prev);
            if(temp != nullptr) {
                ListNode* nextt = temp -> next;
                temp -> next = nullptr;
                temp = nextt;
            }
            else break;
        }

        while(ans.size() != k) ans.push_back(nullptr);

        return ans;
    }
};